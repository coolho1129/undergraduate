#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int Sum(int N)
{
	int sum = 0;
	for (int i = 1; i < N; i++)
	{

		if (N % i == 0)
			sum += i;
	}
	return sum;
}

void main()
{
	FILE *f;
	int N, M;

	f = fopen("input.txt", "r");
	fscanf(f, "%d %d", &N, &M);

	if (Sum(N) == M && Sum(M) == N)
	{
		printf("Amicable\n");
	}
	else
	{
		printf("Not Amicable\n");
	}

	fclose(f);
}
