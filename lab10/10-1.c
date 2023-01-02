#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char string[1000];

	gets(string);

	// printf("%s", string);
	int i;
	int a = strlen(string);

	char *ptoken = strtok(string, " ");

	while (ptoken != NULL)
	{
		// printf("%s\n", ptoken);

		for (i = strlen(ptoken) - 1; i >= 0; i--)

		{
			printf("%c", ptoken[i]);
		}
		printf(" ");
		ptoken = strtok(NULL, " ");
	}
	return 0;
}