#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    puts("Start to find calc server");
    int recv_sock;
    struct sockaddr_in adr;
    int str_len;
    char recv[BUF_SIZE];
    memset(recv, 0, sizeof(recv));

    recv_sock = socket(PF_INET, SOCK_DGRAM, 0);

    memset(&adr, 0, sizeof(adr));
    adr.sin_family = AF_INET;
    adr.sin_addr.s_addr = htonl(INADDR_ANY);
    adr.sin_port = htons(8082);

    if (bind(recv_sock, (struct sockaddr *)&adr, sizeof(adr)) == -1)
    {
        perror("bind failed");
        return -1;
    }

    int send_sock;
    struct sockaddr_in broad_adr;
    char send[BUF_SIZE];
    memset(send, 0, sizeof(send));
    int so_brd = 1;

    send_sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&broad_adr, 0, sizeof(broad_adr));
    broad_adr.sin_family = AF_INET;
    broad_adr.sin_addr.s_addr = inet_addr("255.255.255.255");
    broad_adr.sin_port = htons(8080);

    setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_brd, sizeof(so_brd));
    strcpy(send, "client");
    // puts("send ready");
    sendto(send_sock, send, strlen(send), 0, (struct sockaddr *)&broad_adr, sizeof(broad_adr));
    // puts("send finish");
    // puts("recv ready");
    recvfrom(recv_sock, recv, BUF_SIZE - 1, 0, NULL, 0);
    // puts("recv finish");

    if (strcmp("fail", recv) == 0)
    {
        puts("Fail");
        return 0;
    }
    int port = atoi(recv);
    printf("Found calc server(%d)\n", port);

    int sockfd, cnt, result;
    char buf[1024];
    struct sockaddr_in servaddr;

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

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
        close(sockfd);
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

    write(sockfd, buf, (cnt * sizeof(int) + cnt * sizeof(char)));

    read(sockfd, &result, sizeof(result));

    printf("Operation result: %d\n", result);

    close(sockfd);
    return 0;
}