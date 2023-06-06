#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, cnt, result;
    char buf[1024];
    struct sockaddr_in servaddr;

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
        perror("socket creation failed");
        return -1;
    }

    if (connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connection error");
        return -1;
    }

    memset(buf, 0, sizeof(buf));
    printf("Operand count: ");
    scanf("%d", &cnt);
    buf[0] = (char)cnt;

    if (buf[0] <= 0)
    {
        write(sockfd, buf, sizeof(char));
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

    write(sockfd, buf, ((cnt * sizeof(int)) + (cnt) * sizeof(char)));

    read(sockfd, &result, sizeof(result));

    printf("Operation result: %d\n", result);

    close(sockfd);
    return 0;
}
