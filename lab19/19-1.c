#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
	FILE *fp;
	char ch, name[100];
	char text[1000];
	scanf("%s", name);
	// printf("%s\n", name);

	fp = fopen(name, "r");
	if (fp == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		fputc(ch, stdout);
	}

	fclose(fp);
}