#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double R = 0.0;
	double sum = 0.0;
	int cnt = 0;
	double num[100];
	int i, j;
	double mean = 0;

	for (i = 0;; i++)
	{
		scanf("%lf", &R);

		if (R != 0)
		{
			cnt += 1;
			sum += R;
			num[i] = R;
		}
		else
		{
			break;
		}
	}
	mean = sum / cnt;

	printf("%0.1lf\n", mean);

	for (j = 0; j < cnt; j++)
	{
		if (num[j] < mean)
		{
			printf("%0.1lf ", num[j]);
		}
	}
	return 0;
}
