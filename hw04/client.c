#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    struct hostent *host, *host2;
    struct sockaddr_in addr;

    if (argc != 2 && argc != 3)
    {
        printf("Usage: %s <DomainName> <RemoteAddress>\n", argv[0]);
        return 1;
    }

    if (argc == 2)
    {
        host = gethostbyname(argv[1]);

        if (!host)
        {
            perror("gethostbyname() error");
            return 1;
        }

        printf("gethostbyname()\n");
        printf("Official name: %s \n", host->h_name);

        for (int i = 0; host->h_aliases[i]; i++)
        {
            printf("Aliases %d: %s \n", i, host->h_aliases[i]);
        }

        printf("Addrees type: %s \n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");

        for (int i = 0; host->h_addr_list[i]; i++)
        {
            printf("IP addr %d: %s \n", i, inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
        }

        host2 = gethostbyaddr(host->h_addr_list[0], host->h_length, host->h_addrtype);

        if (!host2)
        {
            host2 = gethostbyaddr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]), host->h_length, host->h_addrtype);
            if (!host2)
            {
                perror("gethostbyaddr() error");
                return 1;
            }
        }

        printf("\ngethostbyaddr()\n");
        printf("Official name: %s \n", host2->h_name);
        for (int i = 0; host2->h_aliases[i]; i++)
        {
            printf("Aliases %d: %s \n", i, host2->h_aliases[i]);
        }

        printf("Address type: %s \n", (host2->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");
        for (int i = 0; host2->h_addr_list[i]; i++)
        {
            printf("IP addr %d: %s \n", i, inet_ntoa(*(struct in_addr *)host2->h_addr_list[i]));
        }
    }

    else
    {
        FILE *f;
        int sockfd, sock_type, state;
        char buf[1024], tmp[1024];
        char *stnum = "2021114818";
        struct sockaddr_in servaddr;

        if (argc < 3)
        {
            printf("usage: ./client remoteAddress remotePort\n");
            return -1;
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            perror("socket creation failed");
            return -1;
        }
        int len = sizeof(sock_type);
        state = getsockopt(sockfd, SOL_SOCKET, SO_TYPE, (void *)&sock_type, &len);

        printf("This socket type is %d(%d)\n", sock_type, SOCK_STREAM);
        f = fopen("copy.txt", "w+");

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(atoi(argv[1]));
        servaddr.sin_addr.s_addr = inet_addr(argv[2]);

        if (connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        {
            perror("connection error");
            return -1;
        }

        int read_cnt;
        memset(buf, 0, sizeof(buf));
        while (read_cnt = read(sockfd, buf, sizeof(buf)) != 0)
        {
            fwrite((void *)buf, sizeof(char), read_cnt, f);
        }

        printf("Received file data\n");

        memset(buf, 0, sizeof(buf));
        rewind(f);
        for (;;)
        {
            read_cnt = fread((void *)buf, sizeof(char), sizeof(buf), f);
            if (read_cnt < sizeof(buf))
            {
                write(sockfd, buf, read_cnt);
                break;
            }
            write(sockfd, buf, strlen(buf));
        }

        fclose(f);
        close(sockfd);
        return 0;
    }
}