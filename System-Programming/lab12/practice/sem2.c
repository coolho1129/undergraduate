#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){

	sem_t *sem;
	
	sem = sem_open("testsem",O_CREAT|0666,1);
	printf("sem = %p\n",sem );
	
	sem wait(sem);
	printf("Testing...\n");
	sleep(10);
	sem_post(sem);

}
