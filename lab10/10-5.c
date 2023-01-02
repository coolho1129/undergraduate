#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int i, j, k;
	int max = 0;
	int sum = 0;
	char MAX[1000] = {0};
	char input1[1000];
	char input2[1000];
	char input3[1000];

	char delimiter[1000] = " .,!\t\n";
	char *ptoken1;
	char *ptoken2;
	char *ptoken3;

	gets(input1);
	gets(input2);
	gets(input3);

	ptoken1 = strtok(input1, delimiter);

	// printf("strlen(%s) = %d\n", ptoken, strlen(ptoken));

	for (i = 0; ptoken1 != NULL; i++)
	{
		if (strlen(ptoken1) > strlen(MAX))
		{

			strcpy(MAX, ptoken1);
		}
		ptoken1 = strtok(NULL, delimiter);
	}
	ptoken2 = strtok(input2, delimiter);

	for (j = 0; ptoken2 != NULL; j++)
	{
		if (strlen(ptoken2) > strlen(MAX))
		{
			strcpy(MAX, ptoken2);
		}
		ptoken2 = strtok(NULL, delimiter);
	}
	ptoken3 = strtok(input3, delimiter);

	for (k = 0; ptoken3 != NULL; k++)
	{
		if (strlen(ptoken3) > strlen(MAX))
		{
			strcpy(MAX, ptoken3);
		}
		ptoken3 = strtok(NULL, delimiter);
	}

	sum = i + j + k;

	// printf("%d %d %d\n", i, j, k);

	printf("%d %s", sum, MAX);

	return 0;
}
