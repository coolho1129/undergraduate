#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int n = 0;
	int money = 1;
	int sum = 0;
	int i;

	for (;;)
	{
		scanf("%d", &n);

		if (n < 0)
			printf("wrong\n");

		else
			break;
	}

	for (i = 0; i < n; i++)
	{

		{
			printf("%d\n", money);
			sum += money;
			money *= 2;
		}
	}

	printf("=%d", sum);

	return 0;
}
