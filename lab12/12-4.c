#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 4번

int main()
{
	int i, j, a[4][4] = {0};
	int sum[4] = {0};
	int SUM[5] = {0};
	int S = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{

			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
		}
	}
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			SUM[j] += a[i][j];
		}
		SUM[4] += SUM[j];
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%4d", a[i][j]);
		}

		printf("%4d\n", sum[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%4d", SUM[i]);
	}

	return 0;
}
