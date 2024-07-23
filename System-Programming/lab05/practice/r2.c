#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
struct Node {
	int a;
	float b;
	char name[12];
};

int main ()
{
	int fd;
	struct Node node;
	fd = open ("data1.bin", O_RDWR | O_CREAT);
	read (fd, &node, sizeof(struct Node));
	printf ("node.a = %d\n", node.a);
	printf ("node.b = %f\n", node.b);
	printf ("node.name = %s\n", node.name);
	close (fd);
}
