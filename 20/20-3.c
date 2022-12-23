#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct account
{
	int accnum;
	char name[30];
	double balance;

} account;

void main()
{
	FILE *fp;
	account act[100] = {
		0,
	};
	char file[100] = {"bank.bin"}, name[100];
	int n, i = 0, cnt = 0;
	double input, output, total = 0;

	fp = fopen(file, "wb");

	if (fp == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	for (;;)
	{
		scanf("%d", &n);

		if (n == 1)
		{
			for (;; i++)
			{
				scanf("%d", &act[i].accnum);
				if (act[i].accnum == -1)
					break;
				scanf("%s %lf", act[i].name, &act[i].balance);
				cnt++;
			}
		}
		else if (n == 2)
		{
			scanf("%s", name);
			for (i = 0; i < cnt; i++)
			{

				if (strcmp(act[i].name, name) == 0)
				{
					printf("%d %s %0.2lf\n", act[i].accnum, act[i].name, act[i].balance);
				}
			}
		}
		else if (n == 3)
		{
			scanf("%s %lf", name, &input);
			for (i = 0; i < cnt; i++)
			{

				if (strcmp(act[i].name, name) == 0)
				{
					act[i].balance += input;
					printf("%d %s %0.2lf\n", act[i].accnum, act[i].name, act[i].balance);
				}
			}
		}
		else if (n == 4)
		{
			scanf("%s %lf", name, &output);
			for (i = 0; i < cnt; i++)
			{

				if (strcmp(act[i].name, name) == 0)
				{
					act[i].balance -= output;
					printf("%d %s %0.2lf\n", act[i].accnum, act[i].name, act[i].balance);
				}
			}
		}
		else if (n == 5)
		{
			for (i = 0; i < cnt; i++)
				total += act[i].balance;

			printf("Total=%0.2lf\n", total);

			for (i = 0; i < cnt; i++)
				printf("%d %s %0.2lf\n", act[i].accnum, act[i].name, act[i].balance);
		}
		else if (n == 6)
		{

			break;
		}
	}
	for (i = 0; i < cnt; i++)
		fwrite(&act[i], sizeof(account), 1, fp);

	fclose(fp);
}