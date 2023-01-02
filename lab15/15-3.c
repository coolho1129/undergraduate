#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void findSum(int data[], int n, int *sum)
{
	int i;
	int *p = data;
	int S = 0;
	for (i = 0; i < n; i++)
	{
		*sum += *(p + i);
	}
}

void main()
{
	int n, i;
	int array[100] = {0};
	int sum = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	findSum(array, n, &sum);
	printf("%d", sum);
}