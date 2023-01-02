
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void printStar(int n);

int main()
{

	int n;
	scanf("%d", &n);
	printStar(n);

	return 0;
}

void printStar(int n)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = n - i - 1; j >= 0; j--)
		{
			printf(" ");
		}

		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}