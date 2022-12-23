#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct iris
{
	double sepal_length;
	double sepal_width;
	double petal_length;
	double petal_width;
	char kind[100];

} iris;

void main()
{
	int n, i, j, k = 0;
	int cnt[3] = {0};
	double sum[3][4] = {0}, mean[3][4] = {0}, sub[3] = {0}, input[4] = {0};
	iris is[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf %lf %lf %s", &is[i].sepal_length, &is[i].sepal_width, &is[i].petal_length, &is[i].petal_width, is[i].kind);

		if (strcmp(is[i].kind, "setosa") == 0)
		{
			sum[0][0] += is[i].sepal_length;
			sum[0][1] += is[i].sepal_width;
			sum[0][2] += is[i].petal_length;
			sum[0][3] += is[i].petal_width;
			cnt[0] += 1;
		}

		else if (strcmp(is[i].kind, "versicolor") == 0)
		{
			sum[1][0] += is[i].sepal_length;
			sum[1][1] += is[i].sepal_width;
			sum[1][2] += is[i].petal_length;
			sum[1][3] += is[i].petal_width;
			cnt[1] += 1;
		}
		else if (strcmp(is[i].kind, "virginica") == 0)
		{
			sum[2][0] += is[i].sepal_length;
			sum[2][1] += is[i].sepal_width;
			sum[2][2] += is[i].petal_length;
			sum[2][3] += is[i].petal_width;
			cnt[2] += 1;
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (cnt[i] != 0)
		{
			for (j = 0; j < 4; j++)
			{
				mean[i][j] = (sum[i][j] / cnt[i]);
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		scanf("%lf", &input[i]);
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			sub[i] += fabs(mean[i][j] - input[j]);
	}
	double min = sub[0];

	for (i = 0; i < 3; i++)
	{
		if (min > sub[i])
		{
			min = sub[i];
			k = i;
		}
	}

	// printf("%d\n", k);
	if (k == 0)
		printf("setosa");
	else if (k == 1)
		printf("versicolor");

	else if (k == 2)
		printf("virginica");
}