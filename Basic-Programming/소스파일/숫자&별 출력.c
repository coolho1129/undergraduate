#define _CRT_SECURE_NO_WARNINGS

1**
12*
123

숫자&별 출력

#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d", j);
			
		}

		for (int k = n-i-1; k>=0; k--)
		{
			printf("*");
		}

		printf("\n");
	}

}