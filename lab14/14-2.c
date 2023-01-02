#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int reversenum(int a)
{
	int b = a % 10;
	a = a / 10;
	printf("%d", b);

	if (a != 0)
		return reversenum(a);
}

int main()
{
	int x;
	scanf("%d", &x);

	reversenum(x);
	return 0;
}