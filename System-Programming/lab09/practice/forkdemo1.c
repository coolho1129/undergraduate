#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	pid_t pid=getpid();
	int result;

	printf("Hello. mypid = %d\n",pid);
	result=fork();
	
	pid=getpid();
	printf("After fork, Hello again. mypid = %d\n",pid);

}
