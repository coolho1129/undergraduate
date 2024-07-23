#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 5번

int main()
{
	int a[5] = {0}, b[5] = {0}, c[10] = {0}, d[10] = {0};
	int i, j;
	int tmp = 0;
	int same = 0, Ccnt = 0, Dcnt = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &b[i]);
	}

	for (i = 0; i < 5; i++)
	{
		same = 0;
		for (j = 0; j < 5; j++)
		{
			if (a[i] == b[j])
			{
				same = 1;
				break;
			}
		}
		if (!same)
		{
			c[Ccnt++] = a[i];
			// Ccnt++;
		}
	}
	for (i = 0; i < 5; i++)
	{
		same = 0;
		for (j = 0; j < 5; j++)
		{
			if (b[i] == a[j])
			{
				same = 1;
				break;
			}
		}
		if (!same)
		{

			d[Dcnt++] = b[i];
			// Dcnt++;
		}
	}

	for (i = 0; i < Ccnt; i++)
	{
		for (j = i + 1; j < Ccnt; j++)
		{
			if (c[i] > c[j])
			{
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
		}
	}

	for (i = 0; i < Dcnt; i++)
	{
		for (j = i + 1; j < Dcnt; j++)
		{
			if (c[i] > c[j])
			{
				tmp = d[i];
				d[i] = d[j];
				d[j] = tmp;
			}
		}
	}

	printf("A-B=");
	for (i = 0; i < Ccnt; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	printf("B-A=");

	for (i = 0; i < Dcnt; i++)
	{
		printf("%d ", d[i]);
	}

	return 0;
}