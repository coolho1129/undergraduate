#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void sortWithoutDupllication(int arry[], int *size)
{
	int i, j;
	int tmp = 0;
	int cnt = 0;

	for (i = 0; i < *size; i++)
	{
		for (j = i + 1; j < *size; j++)
		{
			if (arry[i] > arry[j])
			{
				tmp = arry[i];
				arry[i] = arry[j];
				arry[j] = tmp;
			}
		}
	}

	for (i = 0; i < *size; i++)
	{
		if (arry[i] == arry[i + 1])
		{
			for (j = i + 1; j < *size; j++)
			{
				arry[j] = arry[j + 1];
			}
			(*size)--;
			i--;
		}
	}
}

void main()
{
	int array[100] = {0};
	int i;
	int size = 10;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}

	sortWithoutDupllication(array, &size);

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}
