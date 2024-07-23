#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i, n;
	for (i = 1; i <= 9; i += 3)
	{
		for (n = 1; n <= 9; n++)
		{
			printf("%d*%d=%d\t\t%d*%d=%d\t\t%d*%d=%d\n", i, n, (i * n), (i + 1), (n), ((i + 1) * (n)), (i + 2), (n), ((i + 2) * (n)));
		}
		printf("\n");
	}
	return 0;
}
