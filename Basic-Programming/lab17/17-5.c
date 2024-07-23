#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sol1(); // scanf 사용
void sol2(); // gets 오류 제거

typedef struct
{
	char fname[100];
	int calories;

} Food;

int totalCalories(Food ary[], int size)
{
	int i, sum = 0;
	for (i = 0; i < size; i++)
		sum += ary[i].calories;
	return sum;
}

void main()
{
	sol1();
	printf("\n");
	sol2();
}
void sol1()
{
	Food array[100];
	int i;
	int count = 0;
	for (i = 0;; i++)
	{
		scanf("%s", array[i].fname);
		if (strcmp(array[i].fname, "quit") == 0)
			break;
		scanf("%d", &array[i].calories);
	}

	printf("%d", totalCalories(array, i));
	printf("\n");
}
void sol2()
{
	Food array[100];
	int i;
	int count = 0;
	for (i = 0;; i++)
	{
		gets(array[i].fname);
		gets(array[i].fname);
		if (strcmp(array[i].fname, "quit") == 0)
			break;
		scanf("%d", &array[i].calories);
	}

	printf("%d", totalCalories(array, i));
}