세모 만들기

﻿#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void printStar(int n);
int main()
{
	int n ;
	scanf("%d", &n);
	printStar(n);
}

void printStar(int n)
{
	
	for (int i = 1; i <= n; i++)
	{
		for (int k =n-i;k>0; k--)
		{
			printf(" ");
		}
		
		for (int l = 0; l < i-1; l++)
		{
			printf("*");
		}
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
		
	}
}
