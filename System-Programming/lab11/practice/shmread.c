#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
int main(){
	key_t key=1234;
	int shmid;
	char *shmaddr;
	char buf[100];

	shmid = shmget(key,1024,IPC_CREAT|0666);
	printf("shmid= %d \n",shmid);

	shmaddr=shmat(shmid,NULL,0);

	strcpy(buf,shmaddr);
	printf("buf = [%s]\n",buf);
	
	shmdt(shmaddr);

}

