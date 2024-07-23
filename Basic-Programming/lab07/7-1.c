#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	int count = 0;
	int cnt = 0;
	int num[100];
	int i, j;

	for (i = 0;; i++)
	{
		scanf("%d", &n);
		if (n != 0)
		{
			count += 1;
			num[i] = n;
		}
		else
		{
			break;
		}
	}

	printf("%d\n", count);

	for (j = (count - 1); j >= 0; j--)
	{
		printf("%d ", num[j]);
	}
	return 0;
}
