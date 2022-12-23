#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int lcm(int x, int y);

int main()
{
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);

	printf("%d", lcm(x, y));
	return 0;
}

int lcm(int x, int y)
{
	int i;
	int max = 0;
	int s = 0;

	if (x >= y)
	{
		max = x;
	}
	else
	{
		max = y;
	}

	for (i = max;; i++)
	{
		if (i % y == 0 && i % x == 0)

		{
			s = i;
			break;
		}
	}
	return s;
}
