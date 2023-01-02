#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

void main()
{
	FILE *fp;
	char file[100];
	int n, k, sum = 0, i;
	int **ary;

	scanf("%s", file);

	fp = fopen(file, "r");

	fscanf(fp, "%d", &n);
	ary = (int **)calloc(n, sizeof(int *));
	for (i = 0; i < n; i++)
	{
		ary[i] = (int *)calloc(n, sizeof(int));
		for (k = 0; k < n; k++)
		{
			fscanf(fp, "%d", &ary[i][k]);
		}
	}
	int initMin = ary[0][0];
	for (i = 0; i < n; i++)
	{
		initMin = findMin1D(ary[i], n, initMin);
	}
	printf("%d", initMin);

	fclose(fp);
}