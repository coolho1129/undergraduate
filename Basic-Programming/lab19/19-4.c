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
	int sum = 0;
	scanf("%s %s", &name[0], &name[1]);
	// printf("%s\n", name);

	fp1 = fopen(name[0], "r");
	fp2 = fopen(name[1], "w");

	if (fp1 == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while ((ch = fgetc(fp1)) != EOF)
	{

		if ('0' <= ch && ch <= '9')
		{
			sum += ch - '0';
			fputc(ch, fp2);
		}
	}

	printf("%d", sum);

	fclose(fp1);
	fclose(fp2);
}