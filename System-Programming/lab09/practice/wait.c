#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int sum;
int main(){

	pid_t pid=getpid();
	int result,wait_rt;

	printf("Hello. mypid = %d\n",pid);
	sum=1;
	result=fork();

	if(result==0){
		sleep(5);
		sum+=10;
		printf("sum in child process (%d) = %d addr= %p\n",getpid(),sum,&sum);
		printf("child process work is finished\n");
}
	else{
		wait_rt=wait(NULL);
		sum+=20;
		printf("This is a parent work\n");
		printf("sum in parent process = %d addr= %p\n",sum,&sum);
		printf("wait return value = %d\n",wait_rt);
	}

}
