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
#include <pthread.h>
#define BUF_SIZE 30
#define MAX_CLT 100

int clnt_cnt = 0;
int clnt_socks[MAX_CLT];
pthread_mutex_t mutx;

void *handle_clnt(void *arg);
void send_msg(char *msg, int len);

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    int clnt_adr_sz;
    pthread_t worker;

    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mutx, NULL);
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

    for (;;)
    {
        clnt_adr_sz = sizeof(clnt_adr);

        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);

        pthread_mutex_lock(&mutx);
        clnt_socks[clnt_cnt++] = clnt_sock;
        pthread_mutex_unlock(&mutx);

        pthread_create(&worker, NULL, handle_clnt, (void *)&clnt_sock);
        pthread_detach(worker);
        printf("Connected client Port: %d \n", clnt_adr.sin_port);
    }
    close(serv_sock);
    return 0;
}

void *handle_clnt(void *arg)
{
    int clnt_sock = *((int *)arg);
    int str_len;
    int operand[1024];
    char cnt, id[10], operator[1024], recv[1024], send[1024];
    struct iovec vec[2];

    vec[0].iov_base = id;
    vec[0].iov_len = 4;

    vec[1].iov_base = recv;
    vec[1].iov_len = sizeof(recv);

    for (;;)
    {
        memset(id, 0, sizeof(id));
        memset(recv, 0, sizeof(recv));
        memset(send, 0, sizeof(send));
        readv(clnt_sock, vec, 2);

        if (strcmp(recv, "close") == 0)
        {
            puts("Closed client");
            break;
        }

        memset(operand, 0, sizeof(operand));
        memset(operator, 0, sizeof(operator));

        cnt = recv[0];

        for (int i = 0; i < cnt; i++)
        {
            operand[i] = recv[(i * sizeof(int)) + 1];
        }

        for (int i = 1; i < cnt; i++)
        {
            operator[i] = recv[(cnt * sizeof(int)) + i];
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

        strcat(send, "[");
        strcat(send, id);
        strcat(send, "] ");

        char temp[1024];
        memset(temp, 0, sizeof(temp));

        for (int i = 0; i < cnt; i++)
        {
            sprintf(temp, "%d", operand[i]);
            strcat(send, temp);
            if (i + 1 < cnt)
            {
                memset(temp, 0, sizeof(temp));
                sprintf(temp, "%c", operator[i + 1]);
                strcat(send, temp);
            }
            memset(temp, 0, sizeof(temp));
        }
        sprintf(temp, "%d", result);
        strcat(send, "=");
        strcat(send, temp);

        str_len = strlen(send);
        send_msg(send, str_len);
    }

    pthread_mutex_lock(&mutx);
    for (int i = 0; i < clnt_cnt; i++)
    {
        if (clnt_sock == clnt_socks[i])
        {
            while (i++ < clnt_cnt - 1)
            {
                clnt_socks[i] = clnt_socks[i + 1];
            }
            break;
        }
    }
    clnt_cnt--;
    pthread_mutex_unlock(&mutx);
    close(clnt_sock);
    return NULL;
}

void send_msg(char *msg, int len)
{
    pthread_mutex_lock(&mutx);
    for (int i = 0; i < clnt_cnt; i++)
        write(clnt_socks[i], msg, len);
    pthread_mutex_unlock(&mutx);
}