#include <stdio.h>

int main()
{
	int x = 75;
	
	printf("%d\n", (x & (1 << 5)) ? 1 : 0);
	printf("%d\n", (x | (1 << 4)) | (1<<3) | (1<<2));
	printf("%d\n", (x &~(1 << 2)) & ~(1 << 0));
	printf("%d\n", (x ^ (1 << 3)) ^ (1 << 2));


	
}