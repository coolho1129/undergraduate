#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
	재귀함수 문제로 1학기 족보와 유사함
	1학기 족보코드를 응용하여 만듦
	나머지 문제를 빠르게 풀고 이 문제에 시간을 많이 사용했음
*/
int checkSimilar(long a)
{
	int b;

	if (a / 10 != 0)
	{
		b = abs(((a / 10) % 10) - (a % 10));

		if (b > 1)
		{
			return 0;
		}
		else
			return (checkSimilar(a / 10));
	}
	else
		return 1;
}

void main()
{
	int n;

	for (;;)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		if (checkSimilar(n) == 1)
		{
			printf("yes\n");
		}
		else if (checkSimilar(n) == 0)
		{
			printf("no\n");
		}
	}
}