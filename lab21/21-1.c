#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Time{

	int hour;
	int min;
	int sec;
}Time;


Time elaspedTime(Time start, Time end)
{

	Time elapse;
	
	elapse.hour = end.hour - start.hour;
	
	if (end.min<start.min)
	{
		elapse.hour -= 1;
		elapse.min = 60 + end.min - start.min;
	}
	else
		elapse.min =end.min - start.min;
	
	if (end.sec <start.sec)
	{
		elapse.min -= 1;
		elapse.sec = 60 + end.sec - start.sec;
	}
	else
		elapse.sec = end.sec - start.sec;

	return elapse;
}


void main()
{
	FILE *fp;
	Time time[2] = {0}, elapse;
	char name[30] = { 0 };
	int i = 0;
	
	scanf("%s", name);
	
	fp = fopen(name, "r");

	for (i = 0; i < 2; i++)
		fscanf(fp, "%d:%d:%d", &time[i].hour, &time[i].min, &time[i].sec);
	
	
	elapse=elaspedTime(time[0], time[1]);
	printf("%02d:%02d:%02d", elapse.hour, elapse.min, elapse.sec);
	fclose(fp);
}
