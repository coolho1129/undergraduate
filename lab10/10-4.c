#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int count = 0;
	char str1[1000];
	char str2[1000];
	char str3[1000];
	char punct[1000];

	gets(str1);
	gets(str2);
	gets(str3);

	for (int i = 0; i < strlen(str1); i++)
		if (ispunct(str1[i]) != 0)
		{
			count++;
		}

	for (int i = 0; i < strlen(str2); i++)
		if (ispunct(str2[i]) != 0)
		{
			count++;
		}
	for (int i = 0; i < strlen(str3); i++)
		if (ispunct(str3[i]) != 0)
		{
			count++;
		}

	printf("%d ", count);

	for (int i = 0; i < strlen(str1); i++)
		if (ispunct(str1[i]) != 0)
		{
			printf("%c", str1[i]);
		}
	for (int i = 0; i < strlen(str2); i++)
		if (ispunct(str2[i]) != 0)
		{
			printf("%c", str2[i]);
		}
	for (int i = 0; i < strlen(str3); i++)
		if (ispunct(str3[i]) != 0)
		{
			printf("%c", str3[i]);
		}

	return 0;
}