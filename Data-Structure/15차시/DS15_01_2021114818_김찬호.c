#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define RUNCOL 32
#define RUNROW 10
#define MAXSIZE 1000
int run[RUNCOL][RUNROW] = {0};
int winnerTree[MAXSIZE];
int stack[MAXSIZE];
int top = -1;
int front[MAXSIZE];

int compare(int num1, int num2)
{
	return (num1 <= num2 ? num1 : num2);
}

void makeWinnerTree(int K, int size, int height)
{
	int i = height * 2, j = 0;

	for (int k = i; k <= size; k++)
	{

		winnerTree[k] = run[j][front[j]];
		j++;
	}

	while (height > 1)
	{
		int end = (int)(pow(2, height));
		int low = height - 1;
		int start = (int)(pow(2, low));
		int index = 0;

		for (index = start; index < end; index += 2)
		{
			winnerTree[index / 2] = compare(winnerTree[index], winnerTree[index + 1]);
		}

		if (index == end)
		{
			height--;
		}
	}
	winnerTree[0] = compare(winnerTree[1], winnerTree[2]);
}

int findWinnerRun(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (winnerTree[0] == run[i][front[i]])
			return i;
	}
}

void restructWinnerTree(int k, int size, int height)
{
	front[findWinnerRun(k)]++;
	makeWinnerTree(k, size, height);
}

void push(int item)
{
	if (top == MAXSIZE - 1)
	{
		printf("STACK IS FULL\n");
		exit(0);
	}
	stack[++top] = item;
}

int pop()
{
	if (top == -1)
	{
		printf("STACK IS EMPTY\n");
		exit(0);
	}
	return stack[top--];
}

void levelorder(int size)
{
	printf("Level order: ");
	for (int i = 1; i <= size; i++)
	{
		printf("%d ", winnerTree[i]);
	}
	puts("");
}

void inorder(int size)
{
	int index = 1;
	printf("Inorder: ");
	while (1)
	{
		while (index <= size)
		{
			push(index);
			index *= 2;
		}

		if (top == -1)
			break;

		index = pop();
		printf("%d ", winnerTree[index]);
		index = 2 * index + 1;
	}
	puts("");
}

int main()
{
	FILE *f = fopen("input.txt", "r");
	int N, K, i = 0, j = 0, size = 0, temp = 0, height = 0;

	fscanf(f, "%d", &K);
	temp = K;
	while (temp)
	{
		size += temp;
		temp /= 2;
		height++;
	}

	while (i < K)
	{
		fscanf(f, "%d", &N);

		if (N == -1)
		{
			i++;
			j = 0;
		}
		else
		{
			run[i][j++] = N;
		}
	}

	makeWinnerTree(K, size, height);
	printf("Winner: %d\n", winnerTree[1]);
	levelorder(size);
	inorder(size);

	restructWinnerTree(K, size, height);
	printf("Winner: %d\n", winnerTree[1]);
	levelorder(size);
	inorder(size);

	fclose(f);
}
