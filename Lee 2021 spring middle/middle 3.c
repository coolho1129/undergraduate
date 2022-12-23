#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 3번
void main()
{
	int n = 0, count = 0, i = 0, sum = 0;
	double avg = 0;
	int num[100];
	for (;;)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		else if (n > 0)
		{
			num[count] = n;
			count++;
		}
		else
			continue;
	}
	int min = num[0];
	int max = num[0];
	for (i = 0; i < count; i++)
	{
		sum += num[i];

		if (min > num[i])
		{
			min = num[i];
		}
		if (max < num[i])
		{
			max = num[i];
		}
	}
	avg = (double)sum / count;
	printf("avg:%lf max:%d min:%d", avg, max, min);
}