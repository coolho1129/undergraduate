#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
#define SWAP(a, b, t) \
	{                 \
		t = a;        \
		a = b;        \
		b = t;        \
	}

typedef struct element
{

	int key[MAX];
} element;
element record[MAX], temp;

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
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (record[i].key[k] > record[j].key[k])
				{
					SWAP(record[i], record[j], temp);
					break;
				}

				else if (record[i].key[k] < record[j].key[k])
					break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", record[i].key[j]);
		puts("");
	}
}