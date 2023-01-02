#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	int n,i;
	scanf("%d", &n);

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			printf("Not Prime");
			break;
		}
	}
	if(i==n)
		printf("Prime");



}