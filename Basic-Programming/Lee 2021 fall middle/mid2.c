#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 2번

void main()
{
	int n = 0;
	scanf("%d", &n);
	int i, j;

	for (i = 1; i < n; i++)
	{
		for (j = n - 1; j >= i; j--)
		{
			printf("%d", 0);
		}

		for (j = 1; j < 1 + i; j++)
		{
			printf("%d", j);
		}

		printf("\n");
	}

	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j > i; j--)
		{
			printf("%d", 0);
		}

		for (j = 1; j <= 1 + i; j++)
		{
			printf("%d", j);
		}

		printf("\n");
	}
}