#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <math.h>

int main()
{
	char ISBM[11] = {0};
	scanf("%s", ISBM);
	int idex=0, sum = 0, check_isbm[11] = { 0 }, len = strlen(ISBM), cnt = 0, num = 10;
	for (int i = 0; i < len; i++)
	{
		if ('0' <= ISBM[i] && ISBM[i] <= '9')
			check_isbm[i] = ISBM[i] - '0';

		else if (ISBM[i] == 'X')
			check_isbm[i] = 10;

		else
		{
			check_isbm[i] = 0;
			idex = i;
		}
	}
	
	for (int i = 0; i < len; i++)
	{
		sum += check_isbm[i] * num;
		num--;
		//printf("%d %d\n", sum, num);
	}
	//printf("%d", sum);
	
	for (;;)
	{
		check_isbm[idex]++;
		sum += (check_isbm[idex])*(10-idex);
		if (sum % 11 == 0)
		{
			if(check_isbm[idex]!=10)
			printf("Missing Digit: %d", check_isbm[idex]);
			else
				printf("Missing Digit: X");
			break;
		}
		else
			sum -= check_isbm[idex]*(10 - idex);
	
	}
}