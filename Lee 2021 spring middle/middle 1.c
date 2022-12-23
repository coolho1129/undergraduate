#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 1번
void main()
{
	int a, b, c, d, e;
	int sum = 0;
	double avg = 0;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	sum = a + b + c + d + e;
	avg = (double)sum / 5;
	printf("avg = %lf", avg);
}