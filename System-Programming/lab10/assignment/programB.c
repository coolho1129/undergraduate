#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main ()
{
	char msg[100];
	int fd[2];
	int nread;

	fd[0]=open("fifo1",O_RDONLY);
	fd[1] = open ("fifo2", O_WRONLY);
	printf ("fd[0] = %d\n", fd[0]);
	printf("fd[1]= %d\n",fd[1]);
	
	
	for(;;){
		
		read(fd[0],msg,100);
		
		if(strcmp(msg,"end")==0)
			break;
		strcat(msg,"COOLHO");
		write(fd[1],msg,strlen(msg)+1);	
	}
	

}
