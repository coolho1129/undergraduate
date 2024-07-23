#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char msg[100];
	int fd[2];
	

	fd[0]=open("fifo1", O_WRONLY);
	printf("fd[0]: %d\n",fd[0]);
	fd[1]=open("fifo2",O_RDONLY);
	printf("fd[1]: %d\n",fd[1]);

	for(;;){
		printf("Enter a String: ");
		gets(msg);
		write(fd[0],msg,strlen(msg)+1);
		
		if(strcmp(msg,"end")==0)
			break;
		read(fd[1],msg,100);
		printf("Read: %s\n",msg);

	}
	
	printf("ProgramA is finished\n");



}
