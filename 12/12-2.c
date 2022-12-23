#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// 2번

int sumArrayOne(int arry[], int size)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < size; i++)
	{

		sum += arry[i];
	}
	return sum;
}
int findMinOne(int arry[], int size)
{
	int i, j;
	int min = arry[0];
	for (i = 0; i < size; i++)
	{
		if (min > arry[i])
		{
			min = arry[i];
		}
	}
	return min;
}

int main()
{
	int n, i, j;
	int sum = 0;
	scanf("%d", &n);
	int a[100][100] = {0};

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	int min = a[0][0];

	for (i = 0; i < n; i++)
	{
		sum += sumArrayOne(a[i], n);

		// printf("%d %d\n", min, findMinOne(a[i], n));
		// min = (min>findMinOne(a[i], n))?findMinOne(a[i], n):min;
		if (min > findMinOne(a[i], n))
		{
			min = findMinOne(a[i], n);
		}
	}
	printf("%d %d", sum, min);

	return 0;
}