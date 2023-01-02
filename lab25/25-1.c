#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

void procNumber(char str[], int *num, int *sum)
{
	int cnt = 0;
	for (int i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);
	for (int i = 0; i < strlen(str); i++)
	{
		if ('0' <= str[i] && '9' >= str[i])
		{
			*sum += str[i] - '0';
			// printf("%d\n", str[i]-'0');
			cnt++;
		}
	}
	*num = cnt;
}

void main()
{
	char str[255] = {0};
	int num = 0, sum = 0;

	fgets(str, 255, stdin);
	procNumber(str, &num, &sum);
	printf("%s\nNum = %d, Sum = %d", str, num, sum);
}