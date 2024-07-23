#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 5번

int main()
{
	int i, j;
	int count = 0;
	int a1[100][100] = {0};
	int a2[100][100] = {0};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a1[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a2[i][j]);
		}
	}
	// printf("\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (a1[i][j] == a2[i][j])
			{
				count++;
			}
		}
	}

	if (count == 9)
	{
		printf("same");
	}

	else
	{
		printf("not same");
	}
	return 0;
}