#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

int main(){

	key_t key;
	int shmid;
	int *shmaddr;
	int i,j;
	
	key=1000;
	shmid=shmget(key,sizeof(int),IPC_CREAT|0666);
	
	shmaddr=shmat(shmid,0,0);
	for(int i=0;i<10;i++){
		sleep(1);
		for(int j=0;j<1000000;j++)
			(*shmaddr)++;
	}
	printf("shmaddr value = %d\n",*shmaddr);
	shmdt(shmaddr);


}
