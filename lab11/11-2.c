#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
	char originalString[1000];
	char searchString[1000];
	char checkstring[1000] = {0};
	int count = 0;
	int i = 0;
	gets(originalString);
	gets(searchString);

	int n = strlen(searchString);

	for (i = 0; i < strlen(originalString); i++)
	{

		strncpy(checkstring, &originalString[i], n);
		// printf("%s\n", checkstring);
		if (strcmp(searchString, checkstring) == 0)
		{
			count++;
		}
	}

	printf("%d", count);
}