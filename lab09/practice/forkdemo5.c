#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int sum;
int main(){

	pid_t pid=getpid();
	int result;

	printf("Hello. mypid = %d\n",pid);
	sum=1;
	result=fork();

	if(result==0){
		sleep(2);
		sum+=10;
	;
		printf("sum in child process = %d addr= %p\n",sum,&sum);
}
	else{
		sleep(5);
		sum+=20;
		printf("This is a parent work\n");
		printf("sum in parent process = %d addr= %p\n",sum,&sum);
	
	}

}
