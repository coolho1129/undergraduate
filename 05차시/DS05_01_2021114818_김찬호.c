#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX_DEGREE 1001

typedef struct
{
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

int main()
{
	FILE *f1, *f2;
	f1 = fopen("a.txt", "r");
	f2 = fopen("b.txt", "r");
	int N1 = 0, N2 = 0, degree = 0, index = 0;
	float coef = 0;
	polynomial pol1 = {0}, pol2 = {0}, result = {0};

	fscanf(f1, "%d", &N1);

	for (int i = 0; i < N1; i++)
	{
		fscanf(f1, "%f %d", &coef, &degree);
		if (i == 0)
		{
			pol1.degree = degree;
		}
		pol1.coef[MAX_DEGREE - degree - 1] = coef;
	}

	fscanf(f2, "%d", &N2);

	for (int i = 0; i < N2; i++)
	{
		fscanf(f2, "%f %d", &coef, &degree);
		if (i == 0)
		{
			pol2.degree = degree;
		}
		pol2.coef[MAX_DEGREE - degree - 1] = coef;
	}

	for (int i = 0; i < MAX_DEGREE; i++)
	{

		result.coef[i] = pol1.coef[i] + pol2.coef[i];
	}

	for (int i = 0; i < MAX_DEGREE - 1; i++)
	{
		if (result.coef[i] != 0)
		{
			index = i;
			break;
		}
	}

	printf("%fX^%d", result.coef[index], MAX_DEGREE - index - 1);

	for (int i = index + 1; i < MAX_DEGREE - 1; i++)
	{

		if (result.coef[i] != 0)
		{

			printf("+%fX^%d", result.coef[i], MAX_DEGREE - i - 1);
		}
	}

	if (result.coef[MAX_DEGREE - 1] != 0)
	{
		printf("+%f", result.coef[MAX_DEGREE - 1]);
	}

	fclose(f1);
	fclose(f2);
}