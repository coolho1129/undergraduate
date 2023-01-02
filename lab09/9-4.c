#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int checkLastDigit(int arr[], int size, int num)
{
	int i;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] % 10 == num)
			count++;
	}
	return count;
}

int main()
{
	int size;
	scanf("%d", &size);
	int i, arr[100], j;

	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (j = 0; j < 10; j++)
	{
		printf("%d %d\n", j, checkLastDigit(arr, size, j));
	}

	return 0;
}
