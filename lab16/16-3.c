#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 2번

void add_array(double source1[], double source2[], double target[], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{

		*(target + i) = source1[i] + source2[i];
	}
}

int main()
{
	int m, i, j;
	scanf("%d", &m);
	double array[100][100] = {0};
	double target[100] = {0};
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%lf", &array[i][j]);
		}
	}
	add_array(array[0], array[1], target, m);

	for (j = 0; j < m; j++)
	{
		printf("%0.2lf ", target[j]);
	}

	return 0;
}