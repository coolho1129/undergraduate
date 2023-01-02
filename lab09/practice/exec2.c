#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[]){
	
	char*arglist[3];
	arglist[0]="./test";
	arglist[1]= NULL;

	printf("Before execution\n");
	printf("My pid in exec2: %d\n",getpid());
	execvp("./test",arglist);
	printf("After excution\n");
	

}
