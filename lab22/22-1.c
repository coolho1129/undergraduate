#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
	FILE *fp;
	char file[100];
	int n, s, sum = 0, i;
	int *ary;

	scanf("%s", file);

	fp = fopen(file, "r");

	fscanf(fp, "%d %d", &n, &s);

	ary = (int *)malloc(sizeof(int) * n);

	srand(s);
	for (i = 0; i < n; i++)
	{
		ary[i] = rand() % 10;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
		sum += ary[i];
	}

	printf("\n%0.1lf", (double)sum / n);

	free(ary);
	fclose(fp);
}