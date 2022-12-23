#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SWAP(a, b, t) \
	{                 \
		t = a;        \
		a = b;        \
		b = t;        \
	}
#define MAX 1001
#define HEAP_FULL(n) (n == MAX - 1)
#define HEAP_EMPTY(n) (!n)
#define INF INT_MAX / 3
#define TRUE 1
#define FALSE 0

// 틀린 코드임
typedef struct element
{

	int key[MAX];
} element;
element record[MAX];

void quicksort(int left, int right, int index)
{
	int i, j, pivot;
	element temp;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = record[left].key[index];
		do
		{
			do
				i++;
			while (record[i].key[index] > pivot);
			do
				j--;
			while (record[j].key[index] < pivot);
			if (i < j)
				SWAP(record[i], record[j], temp);

		} while (i < j);
		SWAP(record[left], record[j], temp);
		quicksort(left, j - 1, index);
		quicksort(j + 1, right, index);
	}
}

int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0, m;
	fscanf(f, "%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fscanf(f, "%d", &record[i].key[j]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", record[i].key[j]);
		puts("");
	}
	quicksort(0, n - 1, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", record[i].key[j]);
		puts("");
	}
}
