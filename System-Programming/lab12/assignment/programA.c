#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSIZE 100

int main()
{
    sem_t *sem1, *sem2;
    char buf[100];
    key_t key;
    int shmid;
    char *shmaddr;

    key = 1000;

    shmid = shmget(key, BUFSIZE, IPC_CREAT | 0666);
    shmaddr = shmat(shmid, NULL, 0);

    memset(buf, 0, BUFSIZE);
    memset(shmaddr, 0, BUFSIZE);

    sem1 = sem_open("sem1", O_CREAT, 0666, 0);
    sem2 = sem_open("sem2", O_CREAT, 0666, 0);

    printf("shmid = %d \n", shmid);
    printf("sem1 = %p\n", sem1);
    printf("sem2 = %p\n", sem2);

    for (;;)
    {

        printf("Enter a String to send : ");
        gets(buf);

        // write shared memory
        strcpy(shmaddr, buf);

        sem_post(sem1);
        if (strcmp(buf, "end") == 0)
        {

            break;
        }

        // read shard memory

        sem_wait(sem2);
        strcpy(buf, shmaddr);
        printf("%s\n", buf);
    }
    shmdt(shmaddr);
    printf("Programing A is finished\n");
}
