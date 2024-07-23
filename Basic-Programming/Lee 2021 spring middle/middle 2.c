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

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j >= i; j--)
		{
			printf(" ");
		}

		for (j = 'a'; j < 'a' + i; j++)
		{
			printf("%c", j);
		}

		printf("\n");
	}

	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j > i; j--)
		{
			printf(" ");
		}

		for (j = 'a'; j <= 'a' + i; j++)
		{
			printf("%c", j);
		}

		printf("\n");
	}
}