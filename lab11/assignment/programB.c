#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

int main()
{

    int msgqidA,msgqidB;
    key_t keyA,keyB;
    char buf[100];

    keyA = 1024;
    keyB = 1025;
    msgqidA = msgget(keyA, IPC_CREAT | 0666);
    printf("msgpidA: %d\n", msgqidA);
    msgqidB = msgget(keyB, IPC_CREAT | 0666);
    printf("msgpidB: %d\n", msgqidB);

    for (;;)
    {
        msgrcv(msgqidA, buf, 100, 0, 0);
       if (strcmp(buf, "end") == 0)
            break;
       printf("%s\n",buf);
        strcat(buf, "Cool");
        msgsnd(msgqidB, buf, strlen(buf) + 1, 0);
    }
	printf("program B is finished\n");
}
