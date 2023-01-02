#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct number
{

	char name[30];
	char num[30];
} number;

void main()
{
	FILE *fp;
	number address[100] = {0};
	char file[30] = {0}, name[30] = {0};
	int i = 0, cnt = 0;

	scanf("%s", file);
	scanf("%s", name);
	fp = fopen(file, "r");

	for (i = 0; fscanf(fp, "%s %s", address[i].name, &address[i].num) != EOF; i++)
	{
		if (strcmp(name, address[i].name) == 0)
		{
			printf("%s : %s", address[i].name, address[i].num);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("cannot find");

	fclose(fp);
}