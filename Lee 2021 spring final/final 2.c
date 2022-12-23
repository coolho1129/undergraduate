#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checkMagic(int a)
{
	int b = 0;
	if (a / 10 != 0)
	{
		b = ((a / 10) % 10) - a % 10;
		return checkMagic(a / 10) + b;
	}
	else
		return 0;
}

void main()
{
	int n;

	for (;;)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		if (checkMagic(n) == 0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}