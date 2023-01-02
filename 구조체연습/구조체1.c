#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct time
{
	int hour;
	int min;
	int sec;


}time;


void AfterHourAndHAlf(time *input)
{
	struct time t;
	
	
	if (input->min >= 30)
	{
		input->min -= 30;
		input->hour += 01;
	}
	
	
	else
		input->min += 30;

	
	
	if (input->hour==23)
		input->hour = 00;
	
	else
		input->hour += 01;
	
	

}


main()
{
	struct time t;
	struct time* input = &t;

	printf("시 : 분: 초를 입력해주세요.\n");
	scanf("%2d %2d %2d",&t.hour ,& t.min, &t.sec);
	AfterHourAndHAlf(input);
	printf("%02d:%02d:%02d", t.hour, t.min, t.sec);


}