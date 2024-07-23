#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
/*
	1학기 기말족보와 동일하게 출제됨
*/
void main()
{
	char input[100] = {0};
	int result = 0;
	scanf("%s", input);

	result = input[0] - '0';

	for (int i = 0; i < strlen(input); i += 2)
	{
		if (input[i + 1] == '+')
			result += input[i + 2] - '0';
		else if (input[i + 1] == '-')
			result -= input[i + 2] - '0';
	}
	printf("%d", result);
}