#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define FALSE 0
#define TRUE 1
#define MAXSIZE 1000
#define INF (INT_MAX / 2)

typedef struct node *nodePointer;
typedef struct node
{
	int vertex;
	nodePointer link;
} node;

typedef struct
{
	int count;
	nodePointer link;
} hdnodes;

hdnodes graph[MAXSIZE];

nodePointer insertGraph(nodePointer g, int input)
{
	nodePointer p, curr;
	curr = calloc(1, sizeof(node));
	curr->link = NULL;
	curr->vertex = input;

	if (g == NULL)
	{
		g = curr;
	}
	else
	{
		p = g;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = curr;
	}
	return g;
}

void topSort(hdnodes graph[], int n)
{
	int i, j, k, top;
	nodePointer ptr;
	top = -1;

	for (int i = 0; i < n; i++)
	{
		if (!graph[i].count)
		{
			graph[i].count = top;
			top = i;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (top == -1)
		{
			fprintf(stderr, "\nNetworks has a cycle. Sort termindeate. \n");
			exit(EXIT_FAILURE);
		}
		else
		{
			j = top;
			top = graph[top].count;
			printf("%d ", j);

			for (ptr = graph[j].link; ptr; ptr = ptr->link)
			{
				k = ptr->vertex;
				graph[k].count--;
				if (!graph[k].count)
				{
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}

void main()
{
	FILE *f = fopen("input.txt", "r");
	int N, input, index = 0;
	fscanf(f, "%d", &N);
	nodePointer g[MAXSIZE] = {NULL};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fscanf(f, "%d", &input);
			if (input != 0)
			{
				g[i] = insertGraph(g[i], j);
				graph[j].count++;
			}
		}
		graph[i].link = g[i];
	}

	topSort(graph, N);
	fclose(f);
}
