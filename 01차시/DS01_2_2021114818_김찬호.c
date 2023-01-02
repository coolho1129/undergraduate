#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	int a, b, sum1=0,sum2=0;
	scanf("%d %d", &a, &b);

	for (int i = 1; i < a; i++)
	{
		if (a % i == 0)
			sum1 += i;
	}
	for (int i = 1; i < b; i++)
	{
		if (b % i == 0)
			sum2 += i;
	}
	//printf("%d %d\n", sum1, sum2);
	
	if (sum1 == b&&sum2==a)
		printf("Amicable");
	else
		printf("Not Amicable");

}