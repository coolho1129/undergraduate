#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int chechTwins(int a)
{
	int cnt = 0;
	if ((a / 10) != 0)
	{
		if ((a % 10) == ((a / 10) % 10))
		{
			a = a / 100;
			return chechTwins(a);
		}

		else
		{
			cnt++;
		}
	}
	return cnt;
}

int main()
{

	for (;;)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
			break;

		if (chechTwins(x) == 0)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}