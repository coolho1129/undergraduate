#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFERSIZE 4096
#define COPYMODE 0644

void oops(char *s1,char*s2);

int main(int argc, char * args[]){
	
	int input_fd, output_fd,n_chars;
	char buf[BUFFERSIZE];
	
		if(argc!=3){
			fprintf(stderr,"usage:%s source destination\n",*args);
			exit(1);
		}
		
		/* open files*/
		if((input_fd=open(args[1],O_RDONLY))==-1)
		   oops("Cannot open",args[1]);
	 	
		if((output_fd=creat(args[2],COPYMODE))==-1)
			oops("Cannot creat",args[2]);
		
		/*copy files*/
		while((n_chars=read(input_fd,buf,BUFFERSIZE))>0)
			if(write(output_fd,buf,n_chars)!=n_chars)
				oops("write error to",args[2]);
		
		if(n_chars==-1)
			oops("read error from",args[1]);
		
		/*close files*/
		if(close(input_fd)==-1||close(output_fd)==-1)
			oops("erros closing file","");
				
		
	
	
	
	
	return 0;
}

void oops(char *s1,char*s2){
	fprintf(stderr,"error:%s",s1);
	perror(s2);
	exit(1);
}
