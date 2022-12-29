#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int gcd(int a, int b);

int main()
{
	int a, b;
	scanf("%d\n", &a);
	scanf("%d", &b);
	int GCD = gcd(a, b);
	printf("%d", GCD);

	return 0;
}

int gcd(int a, int b)
{
	int i, MAX, max = 0;

	if (a >= b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	for (i = 1; i <= max; i++)
		if (a % i == 0)
		{
			if (b % i == 0)
			{
				MAX = i;
			}
		}
	return MAX;
}