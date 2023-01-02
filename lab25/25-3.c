#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int main()
{
	int year, month, day;
	int maxday = 30, startday = 1;
	scanf("%d %d %d", &year, &month, &day);

	switch (month)
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
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))

			maxday = 29;

		else
			maxday = 28;
		break;
	}

	if (month != 12)
	{
		if (startday <= day && day <= maxday - 10)
			day += 10;

		else if (day > maxday - 10 && day <= maxday)
		{
			month++;
			day = 10 - (maxday - day);
		}
	}
	else
	{
		if (startday <= day && day <= maxday - 10)
			day += 10;

		else if (day > maxday - 10 && day <= maxday)
		{
			year++;
			month = 1;
			day = 10 - (maxday - day);
		}
	}
	printf("%d %d %d", year, month, day);

	return 0;
}
