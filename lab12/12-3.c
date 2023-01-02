#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 3번
int main()
{
	int i, j, A[4][4] = {0};
	int B[4][4] = {0};

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{

			scanf("%d", &A[i][j]);
			B[j][i] = A[i][j];
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{

			printf("%4d", B[i][j]);
		}
		printf("\n");
	}

	return 0;
}