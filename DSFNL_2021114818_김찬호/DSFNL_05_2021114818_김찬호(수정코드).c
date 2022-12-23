#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SWAP(a,b,t){t=a;a=b;b=t;}
#define MAX 1001
#define HEAP_FULL(n)(n==MAX-1)
#define  HEAP_EMPTY(n)(!n)
#define INF INT_MAX/3
#define TRUE 1
#define FALSE 0

typedef struct node* nodepointer;
typedef struct node {
	int vertex;
	nodepointer link;
}node;

nodepointer graph[MAX];

nodepointer insert(nodepointer h, int input) {
	nodepointer p, curr = calloc(1, sizeof(node));
	curr->link = NULL;
	curr->vertex = input;

	if (h == NULL) {
		h = curr;
	}
	else {
		for (p = h; p->link; p = p->link);
		p->link = curr;
	}
	return h;
}

void  printlist(int n) {
	nodepointer p;
	for (int i = 0; i < n; i++) {
		p = graph[i];
		printf("vertex %d: ", i);
		while (p) {
			printf("%d ", p->vertex);
			p = p->link;
		}
		puts("");
	}
}
int visited[MAX];
int visited2[MAX];
void dfs(int v) {

	nodepointer w;
	visited[v] = TRUE;
	printf("%5d", v);
	w = graph[v];
	while (w) {
		if (visited[w->vertex] == FALSE) {

			dfs(w->vertex);
		}
		w = w->link;
	}

}

nodepointer que[MAX];
int front = -1; int rear = -1;

void bfs(int v) {

	nodepointer w;
	printf("%5d", v);
	visited2[v] = TRUE;
	que[++rear] = v;
	while (front!=rear) {
		v = que[++front];
		for (w = graph[v]; w; w = w->link) {
			if (!(visited2[w->vertex])) {
				printf("%5d", w->vertex);
				que[++rear]=w->vertex;
				visited2[w->vertex] = TRUE;
			}
		}
	}

}

int choose(int* distance, int n, int* find) {
	int min = INT_MAX, minpos = -1;

	for (int i = 0; i < n; i++) {
		if (!find[i] && distance[i] < min) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}


void shortestPath(int start, int** cost, int* distance, int n, int* find, int end) {
	int u;
	for (int i = 0; i < n; i++) {
		find[i] = FALSE;
		distance[i] = cost[start][i];
	}

	int touch[MAX] = { 0 };
	find[start] = TRUE;
	distance[start] = 0;
	touch[start] = 0;

	for (int i = 0; i < n - 2; i++) {
		u = choose(distance, n, find);
		find[u] = TRUE;

		for (int j = 0; j < n; j++) {

			if (!find[j]) {
				if (distance[j] > distance[u] + cost[u][j]) {

					distance[j] = distance[u] + cost[u][j];
					touch[j] = u;
				}
			}


		}


	}
	printf("Distance: %d", distance[end]);

	int temp = end;
	int vertex[MAX];
	int index = 0;
	printf("\nPath: %d ", start);
	while (temp) {
		vertex[index++] = temp;

		temp = touch[temp];
	}

	for (int i = index - 1; i >= 0; i--)
		printf("%d ", vertex[i]);
	//printf("%d ", end);

}

int main() {
	FILE* f = fopen("input.txt", "r");
	int n, start, end, input;
	fscanf(f, "%d %d %d", &n, &start, &end);
	int** cost = calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		cost[i] = calloc(n, sizeof(int));
	}
	int* find = calloc(n, sizeof(int));
	int* distance = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(f, "%d", &input);
			if (input == 0) {
				cost[i][j] = INF;
			}
			else {
				cost[i][j] = input;
				graph[i] = insert(graph[i], j);
			}
		}
	}
	/*	for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++)
				printf("%d ", cost[i][j]);
			puts(" ");
		}*/
	printf("DFS: ");
	dfs(start);
	//printf("4 3 2 0 1 5 6 7");
	puts("");
	printf("BFS: ");
	//printf("4 3 5 2 6 7 0 1");
	bfs(start);
	puts("");
	shortestPath(start, cost, distance, n, find, end);
	puts("");
	//printlist(n);
}