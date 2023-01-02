#include <unistd.h>
#include <stdio.h>

int main(){
	char*arglist[3];
	arglist[0]="ls";
	arglist[1]="-al";
	arglist[2]= NULL;;

	printf("Before execution\n");
	execvp("ls",arglist);
	printf("After execution\n");
	

}
