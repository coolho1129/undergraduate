#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void printBin(int a)
{
	{
		if (a < 2)
		{
			printf("%d", a);
		}
		else
		{
			printBin(a / 2);
			printf("%d", a % 2);
		}
	}
}

void printFloat(double a)
{
	int i = 0;
	int b;
	for (i = 0; i < 10; i++)
	{
		b = a * 2;
		printf("%d", b);
		a = a * 2 - b;
		if (a == 0)
			break;
	}
}

void main()
{
	double x;
	for (;;)
	{
		scanf("%lf", &x);
		if (x == 0.0)
		{
			break;
		}

		printBin(x);
		printf(".");
		printFloat(x - (int)x);
		printf("\n");
	}
}
