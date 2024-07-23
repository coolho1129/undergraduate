#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int num1[100];
	int i = 0;
	int cnt = 0;
	for (i = 0;; i++)
	{

		scanf("%d", &num1[i]);

		if (num1[i] == 0)
			break;
	}

	for (int j = 0; j < i; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (num1[j] > num1[k])
			{
				int tmp = num1[j];
				num1[j] = num1[k];
				num1[k] = tmp;
			}
		}
	}

	printf("%d ", num1[i - 1]);
	printf("%d", num1[0]);

	return 0;
}
