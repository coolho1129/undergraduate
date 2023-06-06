#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <pthread.h>

char id[10];

void *send_msg(void *arg);
void *recv_msg(void *arg);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    pthread_t send_thread, recv_thread;
    void *thread_return;

    memset(id, 0, sizeof(id));

    if (argc != 4)
    {
        printf("Usage : %s <IP> <port> <id>\n", argv[0]);
        exit(1);
    }

    sprintf(id, "%s", argv[3]);
    if (strlen(id) != 4)
    {
        puts("ID have to be 4");
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[2]);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("connection error");
        return -1;
    }

    pthread_create(&send_thread, NULL, send_msg, (void *)&sock);
    pthread_create(&recv_thread, NULL, recv_msg, (void *)&sock);
    pthread_join(send_thread, &thread_return);
    pthread_join(recv_thread, &thread_return);
    close(sock);
    return 0;
}

void *send_msg(void *arg)
{
    int sock = *((int *)arg);
    char send[1024];
    int cnt;
    struct iovec vec[2];

    vec[0].iov_base = id;
    vec[0].iov_len = 4;

    for (;;)
    {
        memset(send, 0, sizeof(send));

        scanf("%d", &cnt);
        send[0] = (char)cnt;

        if (send[0] <= 0)
        {
            printf("OverflowNumber(%d) - Closed client\n", send[0]);
            strcpy(send, "close");
            vec[1].iov_base = send;
            vec[1].iov_len = strlen(send);
            writev(sock, vec, 2);
            close(sock);
            exit(0);
        }

        for (int i = 0; i < cnt; i++)
        {
            scanf("%d", (int *)&send[(i * sizeof(int)) + 1]);
        }

        for (int i = 1; i < cnt; i++)
        {
            scanf(" %c", &send[(cnt * sizeof(int)) + i]);
        }

        vec[1].iov_base = send;
        vec[1].iov_len = (cnt * sizeof(int) + cnt * sizeof(char));

        writev(sock, vec, 2);
    }

    close(sock);

    return NULL;
}
void *recv_msg(void *arg)
{
    int sockfd = *((int *)arg);
    char recv[1024];
    int str_len;

    for (;;)
    {
        memset(recv, 0, sizeof(recv));
        str_len = read(sockfd, recv, sizeof(recv));
        if (str_len == -1)
        {
            return (void *)-1;
        }
        if (str_len != 0)
        {
            printf("%s\n", recv);
        }
    }

    return NULL;
}