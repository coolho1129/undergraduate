#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 2번

int findMin1D(int ary[], int size, int initMin)
{
	int i, min;

	min = initMin;
	for (i = 0; i < size; i++)
	{
		if (ary[i] < min)
			min = ary[i];
	}
	return min;
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
	int initMin = array[0][0];
	for (i = 0; i < n; i++)
	{
		initMin = findMin1D(array[i], m, initMin);
	}
	printf("%d", initMin);

	return 0;
}