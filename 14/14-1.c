#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int GCD(int a, int b)
{
	int max = 0;
	int min = 0;
	if (a > b)
	{
		max = b;
		min = a % max;
		a = max;
		b = min;
	}
	else
	{
		max = a;
		min = b % max;
		b = max;
		a = min;
	}
	if (min == 0)
	{
		return max;
	}
	else
	{
		return GCD(a, b);
	}
}

int main()
{
	int x, y;
	for (;;)
	{
		scanf("%d", &x);
		scanf("%d", &y);

		if (x == 0 && y == 0)
		{
			break;
		}
		else
		{
			printf("%d\n", GCD(x, y));
		}
	}

	return 0;
}