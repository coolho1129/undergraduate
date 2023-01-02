#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main()
{
	char name[4][100]={0};
	int korean[4], math[4], english[4];
	int i;
	int sum[4];

	for (i = 0; i < 4; i++)
	{
		
		scanf("%s %d %d %d",name[i], &korean[i], &english[i], &math[i]);
		
		sum[i] = korean[i] + english[i] + math[i];
		

	
	
	}
	


	for (i = 0; i < 4; i++)
	{
		printf("%s %d %d %d %d\n", name[i], korean[i], english[i], math[i], sum[i]);


	}


}