#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int sumAry1D(int ary[], int size)
{
	int i, sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += ary[i];
	}
	return sum;
}

int main()
{
	int n, m, i, j;
	int array[100][100] = {0};
	int sum[100] = {0};
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", sumAry1D(array[i], m));
		sum[i] = sumAry1D(array[i], m);
	}
	printf("%d", sumAry1D(sum, n));

	return 0;
}