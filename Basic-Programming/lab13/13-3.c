#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char name[3][100] = {0};
	int k[100] = {0};
	int m[100] = {0};
	int e[100] = {0};
	int i;

	for (i = 0; i < 3; i++)
	{
		scanf("%s %d %d %d", name[i], &k[i], &m[i], &e[i]);
	}

	int max[3] = {k[0], m[0], e[0]};
	for (i = 0; i < 3; i++)
	{
		if (max[0] < k[i])
		{
			max[0] = k[i];
		}
		if (max[1] < m[i])
		{
			max[1] = m[i];
		}
		if (max[2] < e[i])
		{
			max[2] = e[i];
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s ", name[i]);

		if (max[0] != k[i])
		{
			printf("%d(-) ", k[i]);
		}
		else
		{
			printf("%d(A) ", k[i]);
		}
		if (max[1] != m[i])
		{
			printf("%d(-) ", m[i]);
		}
		else
		{
			printf("%d(A) ", m[i]);
		}
		if (max[2] != e[i])
		{
			printf("%d(-)\n", e[i]);
		}
		else
		{
			printf("%d(A)\n", e[i]);
		}
	}

	return 0;
}