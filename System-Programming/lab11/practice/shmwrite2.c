#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>

int main(){
	
	key_t key=1235;
	int shmid;
	char *shmaddr;
	int data;;

	shmid = shmget(key,1024,IPC_CREAT|0666);
	printf("shmid= %d \n",shmid);
	shmaddr=shmat(shmid,NULL,0);
	
	printf("Enter an String integer: ");
	scanf("%d",&data);
	
	*((int *)shmaddr) = data;
	
	shmdt(shmaddr);

}

