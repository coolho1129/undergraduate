#include <stdio.h>

int isPrime(int x)
{
	int i, b = 1;
	for (i = 2; i < x; i++)
	{

		if (x % i == 0)
		{
			b = 0;
		}
	}
	return b;
}

void main()
{

	int x;
	scanf("%d", &x);
	printf("%s\n", isPrime(x) ? "prime" : "not prime");
}
