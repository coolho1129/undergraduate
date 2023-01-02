#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int fd;
	int a = 10;
	int b = 20;
	fd = open ("data.bin", O_RDWR | O_CREAT);
	write (fd, &a, sizeof(int));
	write (fd, &b, sizeof(int));
	close (fd);
}
