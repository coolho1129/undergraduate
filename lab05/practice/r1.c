#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char*argv[])
{
	int fd;
	int a = 0;
	int b = 0;
	int result ;
	fd = open ("data.bin", O_RDWR | O_CREAT);

	result = read (fd, &a, sizeof(int));
	printf ("result = %d\n", result);
	result = read (fd, &b, sizeof(int));
	printf ("result = %d\n", result);
	result = read (fd, &b, sizeof(int));
	printf ("result = %d\n", result);

	printf ("a = %d b = %d \n", a, b);
	close (fd);
}
