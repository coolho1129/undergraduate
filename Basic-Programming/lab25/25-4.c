#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef struct diary 
{

	int month;
	int day;
	char consum[100];
	int money;
	


}diary;

void main()
{
	FILE* f;
	diary dia = { 0, };
	int month_day[12][31] = { 0 }, monthlysum[100] = { 0 }, mcnt = 0;

	f = fopen("diary.txt", "r");
	if (f == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while (fscanf(f, "%d.%d %s %d", &dia.month, &dia.day, dia.consum, &dia.money) != EOF)
	{
		month_day[dia.month-1][dia.day-1]+=dia.money;
		
	}

	printf("Daily\n");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (month_day[i][j] != 0)
			{
				printf("%d.%d: %d\n", i + 1, j + 1, month_day[i][j]);
			}
		}
	}
	printf("\nMonthly\n");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			monthlysum[i] += month_day[i][j]; 
			
				
		}
		if (monthlysum[i] != 0)
			printf("%d: %d\n", i + 1, monthlysum[i]);
	}
	



}