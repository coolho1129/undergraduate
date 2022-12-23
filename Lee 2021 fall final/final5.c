#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
	1학기 족보는 입력받은 날짜의 2일 "후"의 날짜를 출력하는 것이였으나 5일 "전"의 날짜를 계산하는 것으로 바꿔서 출제됨
*/

int main()
{
	int year, month, day;
	int startday = 1;
	int month_maxday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d %d %d", &year, &month, &day);

	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		month_maxday[1] = 29;
	else
		month_maxday[1] = 28;

	if (month != 1)
	{
		if (day - startday < 5)
		{
			month--;
			day = month_maxday[month - 1] + day - 5;
		}
		else
		{
			day -= 5;
		}
	}
	else
	{
		if (day - startday < 5)
		{
			year--;
			month = 12;
			day = month_maxday[11] + day - 5;
		}
		else
		{
			day -= 5;
		}
	}
	printf("%d %d %d", year, month, day);
}