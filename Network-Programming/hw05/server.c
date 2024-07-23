#define _XOPEN_SOURCE 200
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/signalfd.h>
#include <sys/wait.h>

void read_childproc(int sig)
{
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status))
    {
        printf("removed proc id: %d \n", pid);
    }
}

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock, operand[1024], state;
    char buf[1024], operator[1024], cnt;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t adr_sz;
    pid_t pid;
    struct sigaction act;

    if (argc < 2)
    {
        printf("usage:./server localPort\n");
        return -1;
    }

    if ((serv_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        return -1;
    }

    int enable = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));

    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) < 0)
    {
        perror("blind failed");
        return -1;
    }

    if (listen(serv_sock, 5) < 0)
    {
        perror("socket failed");
        return -1;
    }

    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);

    int fds[2];

    pipe(fds);
    pid = fork();

    if (pid == 0)
    {
        FILE *fp = fopen("log.txt", "wt");
        // puts("file open\n");
        char log[1024];
        int len;

        while (1)
        {
            memset(log, 0, sizeof(log));
            // puts("waiting send");
            len = read(fds[0], log, sizeof(log));
            if (strcmp("q", log) == 0)
                break;
            log[len++] = '\n';

            fwrite((void *)log, sizeof(char), len, fp);
        }

        fclose(fp);
        return 0;
    }

    for (;;)
    {
        adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);

        if (clnt_sock == -1)
        {
            continue;
        }
        else
        {
            puts("new client connected...");
        }

        pid = fork();

        if (pid == 0)
        {
            close(serv_sock);
            char send[1024], temp[1024];
            memset(send, 0, sizeof(send));
            memset(temp, 0, sizeof(temp));
            int len;

            memset(operand, 0, sizeof(operand));
            memset(buf, 0, sizeof(buf));
            memset(operator, 0, sizeof(operator));

            read(clnt_sock, &cnt, sizeof(char));

            if (cnt <= 0)
            {
                printf("Save File(%d)\n", cnt);
                strcpy(send, "q");
                len = strlen(send);
                write(fds[1], send, len);
                close(clnt_sock);
                return 0;
            }

            // printf("Operand count: %d\n", cnt);

            for (int i = 0; i < cnt; i++)
            {
                read(clnt_sock, &operand[i], sizeof(int));
                // printf("Operand %d: %d\n", i, operand[i]);
            }

            for (int i = 1; i < cnt; i++)
            {
                read(clnt_sock, &operator[i], sizeof(char));
                // printf("Operator %d: %c\n", i, operator[i]);
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

            // printf("Operation result: %d\n", result);
            int mypid = getpid();

            sprintf(send, "%d", mypid);

            len = strlen(send);
            send[len++] = ':';
            send[len++] = ' ';

            for (int i = 0; i < cnt; i++)
            {
                sprintf(temp, "%d", operand[i]);
                strcat(send, temp);
                if (i + 1 < cnt)
                {
                    len = strlen(send);
                    send[len++] = operator[i + 1];
                }
                memset(temp, 0, sizeof(temp));
            }

            len = strlen(send);
            send[len++] = '=';
            sprintf(temp, "%d", result);
            strcat(send, temp);
            len = strlen(send);

            printf("%s\n", send);
            write(clnt_sock, &result, sizeof(result));
            write(fds[1], send, len);

            close(clnt_sock);

            return 0;
        }

        else
        {
            close(clnt_sock);
        }

        // puts("test3");
    }

    close(serv_sock);

    return 0;
}