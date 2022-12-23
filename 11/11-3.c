#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i, sum = 0;
	for (i = 1; i < argc; i++)
	{
		sum += atoi(argv[i]);
		}
	printf("%d %d", (i - 1), sum);

	return 0;
}
