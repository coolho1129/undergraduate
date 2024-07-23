#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/uio.h>

int main(int argc, char **argv)
{
    int sockfd, cnt, result;
    char buf[1024], mod[1024], id[1024], log[10000];
    struct sockaddr_in servaddr;
    struct iovec vec[3];

    if (argc < 3)
    {
        printf("usage: ./client remoteAddress remotePort\n");
        return -1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = inet_addr(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket creation failed\n");
        return -1;
    }

    memset(mod, 0, sizeof(mod));
    memset(id, 0, sizeof(id));

    printf("Mode: ");
    scanf("%s", mod);
    vec[0].iov_base = mod;
    vec[0].iov_len = strlen(mod);

    if (((strcmp("save", mod) && strcmp("quit", mod)) && strcmp("load", mod)))
    {
        printf("supported mode: save load quit\n");
        return -1;
    }

    if (connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("connection error\n");
        return -1;
    }

    if (strcmp("quit", mod) == 0)
    {
        writev(sockfd, vec, 3);
    }

    else
    {
        printf("ID: ");
        scanf("%s", id);

        if (strlen(id) != 4)
        {
            puts("Error: ID length must be 4");
            return -1;
        }

        vec[1].iov_base = id;
        vec[1].iov_len = strlen(id);

        if (strcmp("load", mod) == 0)
        {
            writev(sockfd, vec, 3);
            read(sockfd, log, sizeof(log));
            printf("%s", log);
        }

        else if (strcmp("save", mod) == 0)
        {
            memset(buf, 0, sizeof(buf));
            printf("Operand count: ");
            scanf("%d", &cnt);
            buf[0] = (char)cnt;

            if (buf[0] <= 0)
            {
                printf("Overflow will happen(%d)\n", buf[0]);
                return -1;
            }

            for (int i = 0; i < cnt; i++)
            {
                printf("Operand %d: ", i);
                scanf("%d", (int *)&buf[(i * sizeof(int)) + 1]);
            }

            for (int i = 1; i < cnt; i++)
            {
                printf("Operator %d : ", i - 1);
                scanf(" %c", &buf[(cnt * sizeof(int)) + i]);
            }

            vec[2].iov_base = buf;
            vec[2].iov_len = (cnt * 4) + cnt;

            writev(sockfd, vec, 3);
            read(sockfd, &result, sizeof(result));
            printf("Operation result: %d\n", result);
        }
    }

    close(sockfd);
    return 0;
}
