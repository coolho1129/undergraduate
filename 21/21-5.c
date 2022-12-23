#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct date
{
	int year;
	int month;
	int day;
	char wrong[30];

} date;

date cal(date dates)
{
	date output;
	int maxday = 30, startday = 1;
	switch (dates.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxday = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:

		maxday = 30;
		break;

	case 2:
		if ((dates.year % 4 == 0) && (dates.year % 100 != 0) || (dates.year % 400 == 0))

			maxday = 29;

		else
			maxday = 28;
		break;
	}

	if (dates.month != 12)
	{
		if (startday <= dates.day && dates.day <= maxday - 1)
			dates.day += 1;

		else if (dates.day == maxday)
		{

			dates.month += 1;
			dates.day = 1;
		}
		else if (dates.day > maxday)
			strcpy(dates.wrong, "wrong input");
	}

	else
	{
		if (startday <= dates.day && dates.day <= maxday - 1)
			dates.day += 1;
		else if (dates.day == maxday)
		{
			dates.year += 1;
			dates.month = 1;
			dates.day = 1;
		}
		else if (dates.day > maxday)
			strcpy(dates.wrong, "wrong input");
	}
	output = dates;
	return output;
}

void main()
{
	FILE *fp1, *fp2;
	date input = {
			 0,
		 },
		 output = {
			 0,
		 };
	char name[2][30];

	scanf("%s %s", name[0], name[1]);
	fp1 = fopen(name[0], "r");
	fp2 = fopen(name[1], "w");

	while (fscanf(fp1, "%d %d %d", &input.year, &input.month, &input.day) != EOF)
	{
		output = cal(input);
	}

	if (strcmp(output.wrong, "wrong input") == 0)
	{
		fprintf(fp2, "%s", output.wrong);
	}
	else
	{
		fprintf(fp2, "%d.%d.%d", output.year, output.month, output.day);
	}
	fclose(fp1);
	fclose(fp2);
}