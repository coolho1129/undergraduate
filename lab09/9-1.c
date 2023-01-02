#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int max(int a, int b, int c)
{

	int max = a;
	int M = 0;
	if (b > c)
	{
		M = b;
	}
	else
	{
		M = c;
	}

	if (M > max)
	{
		max = M;
	}
	return max;
}

int min(int a, int b, int c)
{
	int min = a;
	int m = 0;
	if (b < c)
	{
		m = b;
	}
	else
	{
		m = c;
	}

	if (m < min)
	{
		min = m;
	}
	return min;
}
int middle(int a, int b, int c)
{
	int MIN, MAX;
	int middle;
	MIN = min(a, b, c);
	MAX = max(a, b, c);

	if (MIN < a && a < MAX)
	{
		middle = a;
	}
	else if (MIN < b && b < MAX)
	{
		middle = b;
	}
	else if (MIN < c && c < MAX)
	{
		middle = c;
	}

	return middle;
}

int main()
{
	for (;;)
	{
		int a, b, c;
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		if ((a == 0) && (b == 0) && (c == 0))
		{
			break;
		}
		printf("%d %d %d\n", max(a, b, c), min(a, b, c), middle(a, b, c));
	}

	return 0;
}