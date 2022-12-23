#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int  factorial(int n)
{
	int  result = 1;
	for (int i = n; i > 1; i--)
		result *= i;
	return result;

}

void factorial_sum(int n,int k)
{
	int result = 0;
	for (;;)
	{
		if (n == 0)
			break;
		result+=factorial(n % 10);
		n /= 10;
	}
	k--;
	printf(" %d",result);
	if (k == 1)
		return 0;
	factorial_sum(result,k);




}



int main()
{
	int N, K, list[1000] = {0};
	scanf("%d %d", &N, &K);
	printf("%d", N);
	factorial_sum(N,K);
	
}