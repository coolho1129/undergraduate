#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void main()
{
	FILE *f;
	int N, min = INT_MAX, max = INT_MIN, sum = 0, cnt = 0;

	f = fopen("input.txt", "r");
	while (fscanf(f, "%d", &N) != EOF)
	{
		if (min > N)
			min = N;
		if (max < N)
			max = N;

		sum += N;
		cnt++;
	}

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
	printf("Avg: %d\n", (sum / cnt));
	fclose(f);
}
