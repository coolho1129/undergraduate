#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
	FILE *fp1, *fp2;
	char ch, name[2][100];

	scanf("%s %s", &name[1], &name[2]);
	// printf("%s\n", name);

	fp1 = fopen(name[1], "r");
	fp2 = fopen(name[2], "w");
	if (fp1 == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}
	// fp2 = fopen(name[2], "w");
	while ((ch = fgetc(fp1)) != EOF)
	{

		fputc(toupper(ch), stdout);
		fputc(toupper(ch), fp2);
	}

	// fgetc(fp2);

	fclose(fp1);
	fclose(fp2);
}