#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


typedef struct grade {
	double mid;
	double fin;
	char name[12];
}grade;

int main ()
{
	int in_fd,out_fd;
	grade input_st[5],output_st[5];
	
	input_st[0].mid=80.7;
	input_st[0].fin=50.8;
	strcpy(input_st[0].name,"JANG");
	
	input_st[1].mid=97.5;
	input_st[1].fin=79.4;
	strcpy(input_st[1].name,"KIM");
	
	input_st[2].mid=5.8;
	input_st[2].fin=2.3;
	strcpy(input_st[2].name,"LEE");
	
	input_st[3].mid=78.56;
	input_st[3].fin=99.5;
	strcpy(input_st[3].name,"LUIS");
	
	input_st[4].mid=37.8;
	input_st[4].fin=57.5;
	strcpy(input_st[4].name,"PRADA");
	
	in_fd = open ("input.txt", O_RDWR | O_CREAT);
	
	for(int i=0;i<5;i++)
		write (in_fd, &input_st[i], sizeof(grade));
			   
	
	close(in_fd);		   
	
	out_fd=open ("input.txt", O_RDWR | O_CREAT);
			   
	for(int i=0;i<5;i++){
		read(out_fd, &output_st[i], sizeof(grade));
		printf("name: %s mid: %lf fin: %lf\n",output_st[i].name,output_st[i].mid,output_st[i].fin);
	}
			 
	close(out_fd);
		
	
			   
}