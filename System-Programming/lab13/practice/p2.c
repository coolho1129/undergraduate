#include <stdio.h>
#include <pthread.h>

void *func(void *arg){
	int i;
	for (i=0;i<5;i++){
		printf("It is working\n");
		sleep(1);
	}
}

int main(){

		pthread_t thrd1,thrd2;
		int result,status;
		
		result=pthread_create(&thrd1,NULL,func, NULL);
		result=pthread_create(&thrd2,NULL,func,NULL);
		
		for(int i=0;i<10;i++){
			printf("Main work...\n");
			usleep(500000);

		}
		pthread_join(thrd1,&status);
		pthread_join(thrd2,&status);

}
