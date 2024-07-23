#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	printf("mypid is %d\n",getpid());
	fork();
	fork();
	fork();
	printf("mypid is %d\n",getpid());

}
