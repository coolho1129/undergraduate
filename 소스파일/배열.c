#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

//2차원 배열 동적 생성
void eg1()
{
	int** table;
	int i, k, rownum, colnum;

	scanf("%d %d", &rownum, &colnum);
	table = (int**)calloc(rownum, sizeof(int*));

	for (i = 0; i < rownum; i++)
	{
		table[i] = (int*)calloc(colnum, sizeof(int));
		for (k = 0; k < colnum; k++)
			scanf("%d", &table[i][k]);
	}

	for (i = 0; i < rownum; i++)
	{
		for (k = 0; k < colnum; k++)
			printf("%d", table[i][k]);
		printf("\n");
	}
}

//이차원 배열에서 최소값 찾기
int findMin1D(int ary[], int size, int initMin)
{
	int i, min;

	min = initMin;
	for (i = 0; i < size; i++)
	{
		if (ary[i] < min)
			min = ary[i];

	}
	return min;

}