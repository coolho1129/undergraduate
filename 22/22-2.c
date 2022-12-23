#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int n=0;
int *buildArray()
{
	int i;
	scanf("%d", &n);
	int *input = (int*)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}
	
	return input;
}

int findMin(int *ary)
{
	int i,min = ary[0];
	
	for (i = 0; i <n; i++)
	{
		if (min > ary[i])
			min = ary[i];
	}
		return min;
}

void main()
{
	FILE* fp;
	char file[100];
	int  n, s, sum = 0, i;
	int *input;
	
	scanf("%s", file);

	fp = fopen(file, "w");
	
	fprintf(fp, "%d",findMin(buildArray()));
	
	fclose(fp);
}