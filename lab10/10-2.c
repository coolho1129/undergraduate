#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char string[1000];

	gets(string);

	int num = atoi(string);
	int result = num + 15;
	printf("%d+%d=%d", num, 15, result);

	return 0;
}
