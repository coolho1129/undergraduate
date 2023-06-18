#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1001

int winner[MAX];
int loser[MAX];

void levelorder(int height)
{
	printf("Winner Tree Level Order: ");
	for (int i = 1; i < pow(2, height); i++)
	{
		printf("%d ", winner[i]);
	}
	puts("");
	printf("Loser Tree Level Order: ");
	for (int i = 1; i < pow(2, height); i++)
	{
		printf("%d ", loser[i]);
	}
}

int run[MAX];
void makeWinnertree(int height)
{
	int low = height - 1;
	int j = 0;
	int start = pow(2, low), end = pow(2, height);

	for (int i = start; i < end; i++)
	{
		winner[i] = run[j];
		// printf("%d ", winner[i]);
		j++;
	}

	while (height)
	{

		for (int i = start; i < end; i += 2)
		{
			winner[i / 2] = ((winner[i] <= winner[i + 1]) ? winner[i] : winner[i + 1]);
			// printf("%d ", winner[i / 2]);
		}
		height--;
		low = height - 1;
		start = pow(2, low), end = pow(2, height);
	}
}

void makelosertree(int height)
{
	int low = height - 1;
	int j = 0;
	int start = (int)pow(2, low), end = (int)pow(2, height);

	for (int i = start; i < end; i++)
	{
		loser[i] = winner[i];
	}

	for (int i = start; i < end; i += 2)
	{
		loser[i / 2] = ((winner[i] >= winner[i + 1]) ? winner[i] : winner[i + 1]);
	}
	while (height)
	{

		for (int i = start; i < end; i += 2)
		{
			loser[i / 2] = ((winner[i] >= winner[i + 1]) ? winner[i] : winner[i + 1]);
		}
		height--;
		low = height - 1;
		start = pow(2, low), end = pow(2, height);
	}
}

int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0, m;
	fscanf(f, "%d %d", &n, &m);
	int height = 0;
	int temp = n;
	while (temp)
	{
		temp /= 2;
		height++;
	}

	// printf("%d ", height);

	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &run[i]);
	}

	makeWinnertree(height);
	makelosertree(height);
	printf("Winner: %d\n", winner[1]);
	levelorder(m);
}