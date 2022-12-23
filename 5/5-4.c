#include <stdio.h>
int main()
{
	int n, a = 0, b = 0, c = 0, d = 0, sum = 0;
	scanf("%d", &n);

	if (n > 1000)
	{
		a = 1000 * 0.09;
		printf("1000 * 0.09 = 90\n");
		sum = a;
	}
	else
	{
		a = n * 0.09;
		printf("%d * 0.09 = %d\n", n, a);
		sum = a;
	}
	if (n > 4000)
	{
		b = 3000 * 0.18;
		printf("3000 * 0.18 = %d\n", b);
		sum += b;
	}
	else
	{
		b = (n - 1000) * 0.18;

		if (b > 0)
		{
			printf("%d * 0.18 = %d\n", (n - 1000), b);
			sum += b;
		}
	}
	if (n > 8000)
	{
		c = 4000 * 0.27;
		printf("4000 * 0.27 = %d\n", c);
		sum += c;
		d = (n - 8000) * 0.36;
		if (d > 0)

			printf("%d * 0.36 = %d\n", (n - 8000), d);
		sum += d;
	}

	else
	{

		c = (n - 4000) * 0.27;
		if (c > 0)
		{
			printf("%d * 0.27 = %d\n", (n - 4000), c);
			sum += c;
		}
	}

	printf("= %d", sum);

	return 0;
}
