#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Money
{

	int all;
	int won[8];

} Money;

Money moneycnt(int all)
{
	Money money;
	money.won[0] = all / 50000;
	all -= money.won[0] * 50000;
	money.won[1] = all / 10000;
	all -= money.won[1] * 10000;
	money.won[2] = all / 5000;
	all -= money.won[2] * 5000;
	money.won[3] = all / 1000;
	all -= money.won[3] * 1000;
	money.won[4] = all / 500;
	all -= money.won[4] * 500;
	money.won[5] = all / 100;
	all -= money.won[5] * 100;
	money.won[6] = all / 50;
	all -= money.won[6] * 50;
	money.won[7] = all / 10;
	all -= money.won[7] * 10;

	return money;
}

void main()
{
	FILE *fp1, *fp2;
	Money money, output;
	char file[2][30] = {0}, name[8][30] = {"50,000", "10,000", "5,000", "1,000", "500", "100", "50", "10"};
	int i = 0, j = 0, tmp;

	scanf("%s %s", file[0], file[1]);
	fp1 = fopen(file[0], "r");
	fp2 = fopen(file[1], "w");

	while (fscanf(fp1, "%d", &money.all) != EOF)
	{
		output = moneycnt(money.all);
	}
	for (i = 0; i < 8; i++)
	{
		if (output.won[i] != 0)
			fprintf(fp2, "%s:%d\n", name[i], output.won[i]);
	}
	fclose(fp1);
	fclose(fp2);
}