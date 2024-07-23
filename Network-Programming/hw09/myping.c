#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define PACKETSIZE 64
struct packet
{
    struct icmphdr hdr;
    char msg[PACKETSIZE - sizeof(struct icmphdr)];
};

int pid = -1;
struct protoent *proto = NULL;

/*--------------------------------------------------------------------*/
/*--- checksum - standard 1s complement checksum                   ---*/
/*--------------------------------------------------------------------*/
unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

/*--------------------------------------------------------------------*/
/*--- display - present echo info                                  ---*/
/*--------------------------------------------------------------------*/
void display(void *buf, int bytes)
{
    int i;
    struct iphdr *ip = buf;
    struct icmphdr *icmp = buf + ip->ihl * 4;
    struct in_addr addr;

    printf("----------------\n");

    addr.s_addr = ip->saddr;

    printf("IPv%d: hdr-size=%d pkt-size=%d protocol=%d TTL=%d src=%s ",
           ip->version, ip->ihl * 4, ntohs(ip->tot_len), ip->protocol,
           ip->ttl, inet_ntoa(addr));

    addr.s_addr = ip->daddr;

    printf("dst=%s\n", inet_ntoa(addr));
    if (icmp->un.echo.id == pid)
    {
        printf("ICMP: type[%d/%d] checksum[%d] id[%d] seq[%d]\n\n",
               icmp->type, icmp->code, ntohs(icmp->checksum),
               icmp->un.echo.id, icmp->un.echo.sequence);
    }
}

/*--------------------------------------------------------------------*/
/*--- listener - separate process to listen for and collect messages--*/
/*--------------------------------------------------------------------*/
void listener(void)
{
    int sd;
    const int val = 255;
    struct sockaddr_in addr;
    unsigned char buf[512];

    sd = socket(PF_INET, SOCK_RAW, proto->p_proto);

    if (sd < 0)
    {
        perror("socket");
        exit(0);
    }
    for (;;)
    {
        int bytes, len = sizeof(addr);

        bzero(buf, sizeof(buf));
        bytes = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &len);
        if (bytes > 0)
        {
            printf("\n***Got message!***\n");
            display(buf, bytes);
        }
        else
            perror("recvfrom");
    }
    exit(0);
}

/*--------------------------------------------------------------------*/
/*--- ping - Create message and send it.                           ---*/
/*--------------------------------------------------------------------*/
void ping(struct sockaddr_in *addr)
{
    const int val = 255;
    int i, sd, cnt = 1;
    struct packet pckt;
    struct sockaddr_in r_addr;
    int bytes;

    sd = socket(PF_INET, SOCK_RAW, proto->p_proto);
    if (sd < 0)
    {
        perror("socket");
        return;
    }
    if (setsockopt(sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
        perror("Set TTL option");
    if (fcntl(sd, F_SETFL, O_NONBLOCK) != 0)
        perror("Request nonblocking I/O");
    for (;;)
    {
        int len = sizeof(r_addr);

        // if ( bytes = recvfrom(sd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&r_addr, &len) > 0 )
        // {
        // 	printf("\n\n***Got message!***\n");
        // 	display(&pckt, bytes);
        // }

        printf("\nMsg #%d\n", cnt);
        bzero(&pckt, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = pid;
        for (i = 0; i < sizeof(pckt.msg) - 1; i++)
        {
            pckt.msg[i] = i + '0';
            // printf("%c\n", pckt.msg[i]);
        }
        pckt.msg[i] = 0;
        pckt.hdr.un.echo.sequence = cnt++;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));
        if (sendto(sd, &pckt, sizeof(pckt), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0)
            perror("sendto");
        sleep(1);
    }
}

/*--------------------------------------------------------------------*/
/*--- main - look up host and start ping processes.                ---*/
/*--------------------------------------------------------------------*/
int main(int count, char *strings[])
{
    struct hostent *hname;
    struct sockaddr_in addr;

    if (count != 2)
    {
        printf("usage: %s <addr>\n", strings[0]);
        exit(0);
    }
    if (count > 1)
    {
        pid = getpid();
        proto = getprotobyname("ICMP");
        hname = gethostbyname(strings[1]);
        bzero(&addr, sizeof(addr));
        addr.sin_family = hname->h_addrtype;
        addr.sin_port = 0;
        addr.sin_addr.s_addr = *(long *)hname->h_addr;

        if (fork() == 0)
        {
            listener();
        }
        else
            ping(&addr);
        wait(0);
    }
    else
        printf("usage: myping <hostname>\n");
    return 0;
}
