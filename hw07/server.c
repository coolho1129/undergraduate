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
#include <time.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{

    if (strcmp(argv[1], "discovery") == 0)
    {
        int port = 0;
        // 1
        int recv_sock;
        struct sockaddr_in adr;
        int str_len;
        char recv[BUF_SIZE];

        recv_sock = socket(PF_INET, SOCK_DGRAM, 0);

        memset(&adr, 0, sizeof(adr));
        adr.sin_family = AF_INET;
        adr.sin_addr.s_addr = htonl(INADDR_ANY);
        adr.sin_port = htons(8080);

        if (bind(recv_sock, (struct sockaddr *)&adr, sizeof(adr)) == -1)
        {
            perror("bind failed");
            return -1;
        }

        puts("Discovery Server operating...");

        for (;;)
        {
            // puts("recv ready");
            memset(recv, 0, sizeof(recv));
            recvfrom(recv_sock, recv, BUF_SIZE - 1, 0, NULL, 0);
            // puts("recv finish");

            int send_sock;
            struct sockaddr_in broad_adr;
            char send[BUF_SIZE];
            memset(send, 0, sizeof(send));
            int so_brd = 1;

            send_sock = socket(PF_INET, SOCK_DGRAM, 0);
            memset(&broad_adr, 0, sizeof(broad_adr));
            broad_adr.sin_family = AF_INET;
            broad_adr.sin_addr.s_addr = inet_addr("255.255.255.255");

            // 3
            if (strcmp("client", recv) == 0)
            {
                broad_adr.sin_port = htons(8082);
                setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_brd, sizeof(so_brd));

                if (port == 0)
                {
                    strcpy(send, "fail");
                }

                else
                {
                    sprintf(send, "%d", port);
                }
            }

            else
            {
                broad_adr.sin_port = htons(8081);
                setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_brd, sizeof(so_brd));
                // setsockopt(send_sock, SOL_SOCKET, SO_REUSEADDR, (void *)&so_brd, sizeof(so_brd));
                if (port == 0)
                {
                    char temp[30];
                    memset(temp, 0, sizeof(temp));
                    sscanf(recv, "%s %d", temp, &port);
                    printf("Calc Server(%d) registered\n", port);
                    strcpy(send, "success");
                }

                else
                {
                    strcpy(send, "fail");
                    // printf("%s\n", send);
                }
            }
            sendto(send_sock, send, strlen(send), 0, (struct sockaddr *)&broad_adr, sizeof(broad_adr));
        }
    }

    else if (strcmp(argv[1], "calc") == 0)
    {
        // 1
        char send[100] = "server: ", temp[BUF_SIZE];
        memset(temp, 0, sizeof(temp));
        srand(time(NULL));
        int port = (rand() % 40001 + 10000);
        sprintf(temp, "%d", port);
        strcat(send, temp);
        puts("Register calc server");

        // 2
        int send_sock;
        struct sockaddr_in broad_adr;
        int so_brd = 1;

        send_sock = socket(PF_INET, SOCK_DGRAM, 0);
        memset(&broad_adr, 0, sizeof(broad_adr));
        broad_adr.sin_family = AF_INET;
        broad_adr.sin_addr.s_addr = inet_addr("255.255.255.255");
        broad_adr.sin_port = htons(8080);

        setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_brd, sizeof(so_brd));

        // puts("read send");
        sendto(send_sock, send, strlen(send), 0, (struct sockaddr *)&broad_adr, sizeof(broad_adr));
        // puts("send finish");

        // 3
        int recv_sock;
        struct sockaddr_in adr;
        char recv[BUF_SIZE];
        memset(recv, 0, sizeof(recv));

        recv_sock = socket(PF_INET, SOCK_DGRAM, 0);

        memset(&adr, 0, sizeof(adr));
        adr.sin_family = AF_INET;
        adr.sin_addr.s_addr = htonl(INADDR_ANY);
        adr.sin_port = htons(8081);

        if (bind(recv_sock, (struct sockaddr *)&adr, sizeof(adr)) == -1)
        {
            perror("bind failed");
            return -1;
        }

        // puts("recv ready");
        recvfrom(recv_sock, recv, BUF_SIZE - 1, 0, NULL, 0);
        // puts("recv finish");

        if (strcmp("success", recv) == 0)
        {
            printf("Calc Server(%d) operating...\n", port);
        }

        else
        {
            puts("Fail");
            return -1;
        }
        close(recv_sock);

        // 4
        int serv_sock, clnt_sock, operand[1024], str_len, fd_max, fd_num;
        char buf[1024], operator[1024], cnt;
        struct sockaddr_in serv_adr, clnt_adr;
        socklen_t adr_sz;
        fd_set reads, copy_reads;
        struct timeval timeout;

        serv_sock = socket(PF_INET, SOCK_STREAM, 0);
        memset(&serv_adr, 0, sizeof(serv_adr));
        serv_adr.sin_family = AF_INET;
        serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_adr.sin_port = htons(port);

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

        FD_ZERO(&reads);
        FD_SET(serv_sock, &reads);
        fd_max = serv_sock;

        for (;;)
        {
            copy_reads = reads;
            timeout.tv_sec = 5;
            timeout.tv_usec = 0;

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
                        str_len = read(i, buf, sizeof(buf));

                        if (str_len == 0)
                        {
                            FD_CLR(i, &reads);
                            close(i);
                            printf("closed client : %d\n", i);
                        }
                        else
                        {
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

                            write(i, &result, sizeof(result));
                        }
                    }
                }
            }
        }
    }

    else
    {
        return -1;
    }
}
