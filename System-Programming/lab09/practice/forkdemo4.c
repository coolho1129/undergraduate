#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	pid_t pid=getpid();
	int result;

	printf("Hello. mypid = %d\n",pid);
	result=fork();

	if(result==0){
		pid=getpid();
		sleep(10);
		printf("After fork,  mypid = %d, result=%d \n",pid,result);

}
	else{
		sleep(12);
		printf("This is a parent work\n");
	
	}

}
