#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define FALSE 0
#define TRUE 1
#define MAXSIZE 100

int cost;
int N;
int index = 0;

struct Edge
{
	int start;
	int end;
	int weight;

} Edge;

struct Edge edges[2 * MAXSIZE];

int parent[MAXSIZE];

void set_init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}

int set_find(int curr)
{
	if (parent[curr] == -1)
	{
		return curr;
	}
	while (parent[curr] != -1)
	{
		curr = parent[curr];
	}
	return curr;
}

void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
	{
		parent[root1] = root2;
	}
}
int MIN(int a, int b)
{
	return (a < b ? a : b);
}

void insertEdge(int **graph)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (graph[i][j] != 0)
			{
				edges[index].start = i;
				edges[index].end = j;
				edges[index++].weight = graph[i][j];
			}
		}
	}
}

void sort()
{
	struct Edge temp;
	for (int i = 0; i < index; i++)
	{
		for (int j = i + 1; j < index; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}
}

void kruskal()
{
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	set_init(N);
	sort();

	int i = 0;
	printf("Selected Edges : ");
	while (edge_accepted < N - 1)
	{
		e = edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset)
		{
			printf("(%d,%d), ", e.start, e.end);
			cost += e.weight;
			edge_accepted++;
			set_union(uset, vset);
		}
		// printf(", ");
		i++;
	}
	printf("\b\b  \nCost: %d", cost);
}

void print_mat(int **Graph)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}

int main()
{

	FILE *f = fopen("input.txt", "r");
	fscanf(f, "%d", &N);
	int **Graph = calloc(N, sizeof(int *));
	for (int i = 0; i < N; i++)
	{
		Graph[i] = calloc(N, sizeof(int));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fscanf(f, "%d", &Graph[i][j]);
		}
	}

	insertEdge(Graph);
	kruskal();
	fclose(f);
}