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
#include <sys/select.h>
#include <sys/time.h>
#include <sys/uio.h>

int savenum = 0;

struct save_data
{
    char id[10];
    char log[100][1024];
    int size;
};

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
    int serv_sock, clnt_sock, operand[1024], str_len, fd_max, fd_num, state;
    char buf[1024], operator[1024], cnt, log[100000], mod[10], id[10], result[1024];
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t adr_sz;
    pid_t pid;
    struct sigaction act;
    fd_set reads, copy_reads;
    struct timeval timeout;
    struct iovec vec[3];
    struct save_data data[20];

    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) < 0)
    {
        perror("bind failed");
        return -1;
    }

    if (listen(serv_sock, 5) < 0)
    {
        perror("socket failed");
        return -1;
    }

    memset(buf, 0, sizeof(buf));
    memset(mod, 0, sizeof(mod));
    memset(id, 0, sizeof(id));

    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);

    vec[0].iov_base = mod;
    vec[0].iov_len = 4;

    vec[1].iov_base = id;
    vec[1].iov_len = 4;

    vec[2].iov_base = buf;
    vec[2].iov_len = sizeof(buf);

    int fds[2][2];

    pipe(fds[0]);
    pipe(fds[1]);
    pid = fork();

    if (pid == 0)
    {
        char recv1[1024], recv2[1024], tmp[1024];

        while (1)
        {
            memset(tmp, 0, sizeof(tmp));
            memset(recv1, 0, sizeof(recv1));
            memset(recv2, 0, sizeof(recv2));

            read(fds[0][0], tmp, sizeof(tmp));

            for (int i = 0; i < 4; i++)
            {
                recv1[i] = tmp[i];
            }

            if (strcmp("quit", recv1) == 0)
                return 0;

            if (strcmp("load", recv1) == 0)
            {

                for (int i = 4; i < 8; i++)
                {
                    recv2[i - 4] = tmp[i];
                }

                int idx = 0;
                char result[10000];
                memset(result, 0, sizeof(result));

                for (idx = 0; idx < savenum; idx++)
                {
                    if (strcmp(recv2, data[idx].id) == 0)
                    {
                        char temp[1024];
                        for (int j = 0; j < data[idx].size; j++)
                        {
                            memset(temp, 0, sizeof(temp));
                            strcat(temp, data[idx].id);
                            strcat(temp, ": ");
                            strcat(temp, data[idx].log[j]);
                            strcat(temp, "\n");
                            strcat(result, temp);
                        }

                        write(fds[1][1], result, strlen(result));
                        break;
                    }
                }

                if (idx == savenum)
                {
                    strcpy(result, "Not exist\n");
                    write(fds[1][1], result, strlen(result));
                }
            }

            else
            {
                for (int i = 4; tmp[i]; i++)
                    recv2[i - 4] = tmp[i];

                int idx = 0;
                for (idx = 0; idx < savenum; idx++)
                {
                    if (strcmp(recv1, data[idx].id) == 0)
                    {
                        strcpy(data[idx].log[data[idx].size++], recv2);
                        break;
                    }
                }

                if (idx == savenum)
                {
                    data[savenum].size = 0;
                    strcpy(data[idx].id, recv1);
                    strcpy(data[savenum].log[data[savenum].size++], recv2);
                    savenum++;
                }
            }
        }
    }

    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    fd_max = serv_sock;

    for (;;)
    {
        copy_reads = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        memset(log, 0, sizeof(log));

        if ((fd_num = select(fd_max + 1, &copy_reads, 0, 0, &timeout)) == -1)
        {
            break;
        }

        if (fd_num == 0)
        {
            continue;
        }

        for (int i = 0; i < fd_max + 1; i++)
        {

            if (FD_ISSET(i, &copy_reads))
            {
                if (i == serv_sock)
                {

                    adr_sz = sizeof(clnt_adr);
                    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
                    FD_SET(clnt_sock, &reads);
                    if (fd_max < clnt_sock)
                    {
                        fd_max = clnt_sock;
                    }
                    printf("connected client : %d\n", clnt_sock);
                }

                else
                {
                    str_len = readv(i, vec, 3);

                    if (str_len == 0)
                    {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("closed client : %d\n", i);
                    }
                    else
                    {
                        if (strcmp("quit", mod) == 0)
                        {
                            puts("quit");
                            write(fds[0][1], mod, strlen(mod));
                        }

                        else if (strcmp("load", mod) == 0)
                        {
                            printf("load from %s\n", id);
                            write(fds[0][1], mod, strlen(mod));
                            write(fds[0][1], id, strlen(id));

                            read(fds[1][0], log, sizeof(log));

                            write(i, log, strlen(log));
                        }

                        else if (strcmp("save", mod) == 0)
                        {

                            char send[1024], temp[1024];
                            memset(send, 0, sizeof(send));
                            memset(temp, 0, sizeof(temp));
                            int len;

                            memset(operand, 0, sizeof(operand));
                            memset(operator, 0, sizeof(operator));

                            cnt = buf[0];

                            for (int k = 0; k < cnt; k++)
                            {
                                operand[k] = buf[(k * sizeof(int)) + 1];
                            }

                            for (int k = 1; k < cnt; k++)
                            {
                                operator[k] = buf[(cnt * sizeof(int)) + k];
                            }

                            int result = operand[0];

                            for (int k = 1; k < cnt; k++)
                            {
                                switch (operator[k])
                                {
                                case '+':
                                    result += operand[k];
                                    break;

                                case '-':
                                    result -= operand[k];
                                    break;

                                case '*':
                                    result *= operand[k];
                                    break;
                                }
                            }

                            for (int k = 0; k < cnt; k++)
                            {
                                sprintf(temp, "%d", operand[k]);
                                strcat(send, temp);
                                if (k + 1 < cnt)
                                {
                                    len = strlen(send);
                                    send[len++] = operator[k + 1];
                                }
                                memset(temp, 0, sizeof(temp));
                            }

                            len = strlen(send);
                            send[len++] = '=';
                            sprintf(temp, "%d", result);
                            strcat(send, temp);

                            printf("save to %s\n", id);
                            // printf("%s\n", send);

                            write(fds[0][1], id, strlen(id));
                            write(fds[0][1], send, strlen(send));

                            write(i, &result, sizeof(result));
                        }
                    }
                }
            }
        }
    }
    close(serv_sock);
    return 0;
}