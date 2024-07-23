#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int sumMultpie(int start, int end, int x);

int main()
{
	int s, e, n, m;
	scanf("%d", &s);
	scanf("%d", &e);
	scanf("%d", &n);
	scanf("%d", &m);

	printf("%d\n", sumMultpie(s, e, n));
	printf("%d\n", sumMultpie(s, e, m));
	printf("%d\n", sumMultpie(s, e, n * m));
	printf("%d\n", sumMultpie(s, e, n) + sumMultpie(s, e, m) - sumMultpie(s, e, n * m));
	printf("%d\n", sumMultpie(s, e, m) - sumMultpie(s, e, n * m));
	printf("%d\n", sumMultpie(s, e, 1) - sumMultpie(s, e, n) - sumMultpie(s, e, m) + sumMultpie(s, e, n * m));

	return 0;
}

int sumMultpie(int start, int end, int x)
{
	int i;
	int sum = 0;
	for (i = start; i < end; i++)
	{
		if (i % x == 0)
		{
			sum += i;
		}
	}
	return sum;
}