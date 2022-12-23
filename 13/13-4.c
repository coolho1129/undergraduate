#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char input[100] = {0};
	int arsci[256] = {0};

	gets(input);
	int i;

	for (i = 0; i < strlen(input); i++)
	{
		arsci[input[i]]++;
	}
	for (i = 'A'; i <= 'z'; i++)
	{
		if (arsci[i] != 0)
			printf("%c:%d\n", i, arsci[i]);
	}

	return 0;
}