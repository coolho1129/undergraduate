#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double getJudgeData()
{
	double r = 0.0;

	for (;;)
	{
		scanf("%lf", &r);

		if (0 <= r && r <= 10)
		{
			break;
		}
	}
	return r;
}

double findLowest(double d[], int n)
{
	int i;
	double min;
	min = d[0];
	for (i = 0; i < n; i++)
	{
		if (min > d[i])
			min = d[i];
	}
	return min;
}

double findHighest(double d[], int n)
{
	int i;
	double max;
	max = d[0];
	for (i = 0; i < n; i++)
	{
		if (max < d[i])
			max = d[i];
	}
	return max;
}

void calcScore(double d[], int n)
{
	int i;
	double sum = 0;
	double S = 0;
	double mean = 0;
	for (i = 0; i < n; i++)
	{
		sum += d[i];
	}
	S = sum - findLowest(d, n) - findHighest(d, n);
	mean = S / (n - 2);

	printf("%.2lf", mean);
}

int main()
{
	int i, n;
	double arr[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		arr[i] = getJudgeData();
	}

	calcScore(arr, n);
	return 0;
}
