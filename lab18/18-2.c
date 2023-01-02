#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

enum day7
{
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};

void main()
{
	typedef enum day7 day;
	char Day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int ymd;
	scanf("%d", &ymd);

	day week;
	week = (ymd + 1) % 7;

	printf("%s\n", Day[week]);
	if (week == 5 || week == 6)
		printf("WEEKEND");
	else
		printf("WEEKDAY");
}