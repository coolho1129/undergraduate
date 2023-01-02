#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void findSum(int data[], int n, int *max, int *min)
{
	int i, j;
	int tmp = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (data[i] > data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}

	*min = data[0];
	*max = data[n - 1];
}

void main()
{
	int n, i;
	int array[100] = {0};
	int max = 0;
	int min = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	findSum(array, n, &max, &min);
	printf("%d %d", max, min);
}