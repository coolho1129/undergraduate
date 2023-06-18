// 4번
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int onecount(int n)
{
	int i, bi[100] = {0};
	int cnt = 0, count = 0;

	for (i = 0;; i++)
	{
		if (n == 0)
			break;

		bi[i] = n % 2;
		n = n / 2;
		cnt++;
	}

	for (i = cnt; i >= 0; i--)
	{
		if (bi[i] == 1)
		{
			count++;
		}
	}
	return count;
}

void printBin(int a)
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


void inttobit(int n)
{
	int i, bi[100] = {0};
	int cnt = 0, count = 0;

	for (i = 0;; i++)
	{
		if (n == 0)
			break;

		bi[i] = n % 2;
		n = n / 2;
		cnt++;
	}

	for (i = cnt; i >= 0; i--)
	{
		printf("%d", bi[i]);
	}
	printf("\n");
}
main()
{
	int n;
	scanf("%d", &n);

	inttobit(n);
        printBin(n);
        puts("");
	printf("%d", onecount(n));
}
