#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>




//5번

int diff(int a[], int b[], int n1, int n2)
{
	int same = 0;
	int i,j,cnt=0,tmp=0;
	int c[100] = {0};
	for (i = 0; i < 5; i++)
	{
		same = 0;
		for (j = 0; j < 5; j++)
		{
			if (a[i] == b[j])
			{
				same = 1;
				break;
			}
		}
		if (!same)
		{
			c[cnt++] = a[i];
			
		}
	}

	for (i = 0; i < cnt; i++)
		a[i] =  0;
	for (i = 0; i < cnt; i++)
	{
		a[i] = c[i];
	}
	for (i = 0; i < cnt; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
		
	
	return cnt;
}

int main()
{
	int i, n;
	int A = 0;
	int B = 0;
	int a[100];
	int b[100];

	printf("A배열의 크기를 입력하시오\n");
	scanf("%d", &A);
	printf("B배열의 크기를 입력하시오\n");
	scanf("%d", &B);

	printf("A배열의 원소를 입력하시오\n");
	for (i = 0; i < A; i++)
		scanf("%d", &a[i]);
	printf("B배열의 원소를 입력하시오\n");
	
	for (i = 0; i < B; i++)
		scanf("%d", &b[i]);

	n = diff(a, b, A, B);
	// printf("%d", n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}