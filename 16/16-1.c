#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 1번
void print1DArray(int d[], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		printf("%d ", *(d + i));
	}
	printf("\n");
}

int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int array[100][100] = {0};

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			print1DArray(array[i] + j, m - j);
		}
	}
	return 0;
}