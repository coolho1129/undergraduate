#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void printDArray(int d[], int n)
{
	int i, j;
	int *p = d;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			printf("%d ", *(p + j));
		}
		printf("\n");
	}
}

void main()
{
	int n, i;
	int array[100] = {0};
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	printDArray(array, n);
}
