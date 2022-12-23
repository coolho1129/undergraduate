#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	FILE* fp;
	char file[100] = {0};
	int  n, min=INT_MAX,max=INT_MIN;

	scanf("%s", file);

	fp = fopen(file, "r");

	while (fscanf(fp, "%d", &n) != EOF)
	{
		if (min > n)
			min = n;
		if (n > max)
			max = n;
	
	}

	printf("MIN: %d\n", min);
	printf("MAX: %d", max);
	fclose(fp);
}