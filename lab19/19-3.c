#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
	FILE *fp;
	char name[100];
	int score, count = 0, grade[1000] = {0};
	scanf("%s", name);
	// printf("%s\n", name);

	fp = fopen(name, "r");

	if (fp == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while (fscanf(fp, "%d", &score) != EOF)
	{

		if (score >= 90)
		{

			grade[count] = score;
			count++;
		}
	};
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", grade[i]);
	}

	fclose(fp);
}