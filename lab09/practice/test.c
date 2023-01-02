#include <stdio.h>

int main(){

	int i;
	printf("My pid: %d\n",getpid());
	for (int i=0;i<5;i++){
		sleep(2);
		printf("COOLHO\n");

	}

}
