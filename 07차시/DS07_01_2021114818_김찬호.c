#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int table[1000];
char string[1001];
char pat[1001];

void failure(char pat[])
{
	int patlen, j = 0, index = 0;
	patlen = strlen(pat);

	table[0] = -1;

	for (int i = 1; i < patlen; i++)
	{
		j = table[i - 1];

		while (pat[i] != pat[j + 1] && j >= 0)
		{

			j = table[j];
		}

		if (pat[i] == pat[j + 1])
		{
			table[i] = j + 1;
		}

		else
			table[i] = -1;
	}

	printf("Failure function:\n");
	printf("j	");

	for (int i = 0; i < patlen; i++)
	{
		printf("%2d ", i);
	}

	printf("\n");

	printf("pat	");
	for (int i = 0; i < patlen; i++)
	{
		printf("%2c ", pat[i]);
	}
	printf("\n");
	printf("f	");

	for (int i = 0; i < patlen; i++)
	{
		printf("%2d ", table[i]);
	}
}

int pmatch(char string[], char pat[])
{

	int i = 0, j = 0, stringlen = strlen(string), patlen = strlen(pat);

	while (i < stringlen && j < patlen)
	{
		if (string[i] == pat[j])
		{
			i++;
			j++;
		}
		else if (j == 0)
			i++;

		else
			j = table[j - 1] + 1;
	}

	return ((j == patlen) ? (i - patlen) : -1);
}

int main()
{

	FILE *f;
	f = fopen("input.txt", "r");

	fscanf(f, "%s %s", string, pat);

	failure(pat);

	printf("\nThe pattern %s is found at the position  %d", pat, pmatch(string, pat));
	fclose(f);
}