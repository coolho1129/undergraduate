#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX_TERMS 1001

typedef struct
{
	int col;
	int row;
	int value;
} term;

term a[MAX_TERMS];

void fasTranspose(term a[], term b[])
{
	int rowTerms[MAX_TERMS], startingPos[MAX_TERMS];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0)
	{
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;

		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;

		startingPos[0] = 1;

		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

int main()
{

	FILE *f1, *f2;

	f1 = fopen("mat1.txt", "r");
	f2 = fopen("mat2.txt", "r");

	int N, M;

	fscanf(f1, "%d %d", &N, &M);

	int **mat1 = (int **)calloc(N, sizeof(int *));

	for (int i = 0; i < N; i++)
	{
		mat1[i] = (int *)calloc(M, sizeof(int));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			fscanf(f1, "%d", &mat1[i][j]);
		}
	}

	fscanf(f2, "%d %d", &N, &M);

	int **mat2 = (int **)calloc(N, sizeof(int *));

	for (int i = 0; i < N; i++)
	{
		mat2[i] = (int *)calloc(M, sizeof(int));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			fscanf(f2, "%d", &mat2[i][j]);
		}
	}

	int **add = (int **)calloc(N, sizeof(int *));

	for (int i = 0; i < N; i++)
	{
		add[i] = (int *)calloc(M, sizeof(int));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			add[i][j] = mat1[i][j] + mat2[i][j];
		}
	}

	a[0].row = N;
	a[0].col = M;

	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			if (add[i][j] != 0)
			{
				a[cnt].value = add[i][j];
				a[cnt].row = i;
				a[cnt].col = j;
				a[0].value = cnt++;
			}
		}
	}

	printf("Matrix Addition :\n");
	// printf("%d %d %d\n", N, M,cnt);

	for (int i = 0; i < cnt; i++)
	{
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
	}

	term result[MAX_TERMS] = {0};

	fasTranspose(a, result);

	printf("Transpose Matrix :\n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%d %d %d\n", result[i].row, result[i].col, result[i].value);
	}

	free(mat1);
	free(mat2);
	free(add);
	fclose(f1);
	fclose(f2);
}