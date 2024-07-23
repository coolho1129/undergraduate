#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    int sockfd, cSockfd, operand[1024];
    char buf[1024], operator[1024], cnt;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;

    if (argc < 2)
    {
        printf("usage:./server localPort\n");
        return -1;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        return -1;
    }

    int enable = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("blind failed");
        return -1;
    }

    for (;;)
    {
        // puts("test1");
        memset(operand, 0, sizeof(operand));
        memset(buf, 0, sizeof(buf));
        memset(operator, 0, sizeof(operator));

        int len = sizeof(cliaddr);
        int buf_len = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliaddr, &len);

        // puts("test2");

        cnt = buf[0];

        if (cnt <= 0)
        {
            printf("Server close(%d)\n", cnt);
            return -1;
        }

        printf("Operand count: %d\n", cnt);

        for (int i = 0; i < cnt; i++)
        {
            operand[i] = buf[i * sizeof(int) + 1];
            printf("Operand %d: %d\n", i - 1, operand[i - 1]);
        }

        for (int i = 1; i < cnt; i++)
        {
            operator[i] = buf[(cnt * sizeof(int)) + i];
            printf("Operator %d: %c\n", i, operator[i]);
        }

        int result = operand[0];
        for (int i = 1; i < cnt; i++)
        {
            switch (operator[i])
            {
            case '+':
                result += operand[i];
                break;

            case '-':
                result -= operand[i];
                break;

            case '*':
                result *= operand[i];
                break;
            }
        }

        printf("Operation result: %d\n", result);

        sendto(sockfd, &result, sizeof(result), 0, (struct sockaddr *)&cliaddr, len);

        // puts("test3");
    }

    close(sockfd);

    return 0;
}