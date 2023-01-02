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
    msgqidB = msgget(keyB, IPC_CREAT | 0666);
  
    printf("msgpidA: %d\n", msgqidA);
    printf("msgpidB: %d\n", msgqidB);
   
   
    for (;;)
    {
        printf("Enter a String to send : ");
        gets(buf);
        msgsnd(msgqidA, buf, strlen(buf) + 1, 0);
        if (strcmp(buf, "end") == 0)
            break;
        msgrcv(msgqidB, buf, 100, 0, 0);
        printf("%s\n", buf);
    }
	printf("program A is finished\n");
}
