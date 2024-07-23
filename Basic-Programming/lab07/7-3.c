#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int num1[5];
	int num2[5];
	int i = 0;
	int cnt = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &num1[i]);
	}

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &num2[i]);
	}

	for (int j = 0; j < 5; j++)
	{
		if (num1[j] == num2[j])
			cnt += 1;
	}

	if (cnt == 5)
		printf("same");
	else
		printf("not same");

	return 0;
}