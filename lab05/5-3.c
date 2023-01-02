#include <stdio.h>
int main()
{
	int n, i, j, k = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%d", j);

		for (k = n; k > i; k--)
			printf("*");

		printf("\n");
	}
	return 0;
}
