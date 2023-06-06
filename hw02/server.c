#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

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

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
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

    if (listen(sockfd, 5) < 0)
    {
        perror("socket failed");
        return -1;
    }

    for (;;)
    {
        // puts("test1");

        if ((cSockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) < 0)
        {
            perror("accept failed");
            return -1;
        }

        // puts("test2");

        memset(operand, 0, sizeof(operand));
        memset(buf, 0, sizeof(buf));
        memset(operator, 0, sizeof(operator));

        read(cSockfd, &cnt, sizeof(char));

        if (cnt <= 0)
        {
            printf("Server close(%d)\n", cnt);
            return -1;
        }

        printf("Operand count: %d\n", cnt);

        for (int i = 0; i < cnt; i++)
        {
            read(cSockfd, &operand[i], sizeof(int));
            printf("Operand %d: %d\n", i, operand[i]);
        }

        for (int i = 1; i < cnt; i++)
        {
            read(cSockfd, &operator[i], sizeof(char));
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

        write(cSockfd, &result, sizeof(result));
        close(cSockfd);

        // puts("test3");
    }

    close(sockfd);

    return 0;
}