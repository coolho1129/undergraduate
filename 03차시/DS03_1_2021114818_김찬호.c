#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void sort(int N, int arry[])
{
	clock_t start, stop;
	double duration;
	start = clock();
	int tmp;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arry[i] < arry[j])
			{
				tmp = arry[i];
				arry[i] = arry[j];
				arry[j] = tmp;
			}
		}
	}

	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("TIME: %lf", duration);
	return 0;
}

int main()
{
	FILE *f1, *f2;
	int N;
	srand(time(NULL));
	scanf("%d", &N);
	f1 = fopen("unsorted.txt", "w");
	f2 = fopen("sorted.txt", "w");

	int *arry = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		arry[i] = (rand() % 100);
		fprintf(f1, "%d ", arry[i]);
	}

	sort(N, arry);

	for (int i = 0; i < N; i++)
	{
		fprintf(f2, "%d ", arry[i]);
	}

	free(arry);
	fclose(f1);
	fclose(f2);
	return 0;
}
