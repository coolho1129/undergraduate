#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100
 int visited1[MAX_VERTICES] = {0};
 int visited2[MAX_VERTICES] = {0};

typedef struct GraphNode* NodePointer;
typedef struct QueNode* QuePointer;

typedef struct GraphNode{
	int vertex;
	NodePointer link;
}GraphNode;

NodePointer graph[MAX_VERTICES];

typedef struct QueNode {
	int vertex;
	QuePointer link;
}QueNode;

QuePointer rear, front;
 
NodePointer appendGraph(NodePointer G,int input) {
	
	NodePointer p,temp = calloc(1, sizeof(GraphNode));
	temp->link = NULL;
	temp->vertex = input;
	
	if (G == NULL) {
		G = temp;
	}
	
	else {
		p = G;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = temp;
	}
	
	return G;

}

void addq(int input) {
	QuePointer temp = calloc(1, sizeof(QueNode));
	temp->vertex = input;
	temp->link = NULL;
	if (front == NULL) {
		front = temp;
		rear = temp;
	}
	else {
		rear->link = temp;
		rear=temp;
	}
}

int deque() {
	QuePointer temp = front;
	int data;
	
	if (front == NULL) {
		printf("Que is empty\n");
		exit(1);
	}
	
	else {
		data = temp->vertex;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		free(temp);
		return data;
	}
}

void dfs(int v) {
	
	NodePointer w;
	visited1[v] = TRUE;
	printf("%5d", v);
	w = graph[v];
	while (w) {
		if (visited1[w->vertex] == FALSE) {

			dfs(w->vertex);
		}
		w = w->link;
	}
	
}

void bfs(int v) {
	
	NodePointer w;
	rear = front = NULL;
	printf("%5d", v);
	visited2[v] = TRUE;
	addq(v);
	while (front) {
		v = deque();
		for (w = graph[v]; w; w=w->link) {
			if (!(visited2[w->vertex])) {
				printf("%5d", w->vertex);
				addq(w->vertex);
				visited2[w->vertex] = TRUE;
			}
		}
	}
	
}

void mat_to_list(int **mat,int N) {
	
	
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < N; j++) {
			if (mat[i][j] != 0) {
				graph[i]=appendGraph(graph[i], j);
			}
		}
		
	}

}
void print_adj_list(int N) {
	NodePointer temp;
	for (int i = 0; i < N; i++) {
		printf("Vertex %5d: ", i);
		temp = graph[i];
		for (; temp; temp = temp->link) {
			printf("%5d ", temp->vertex);
		}
		puts("");
	}
}
void print_adj_mat(int N,int **Graph) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}

int main() {

	FILE* f = fopen("input.txt", "r");
	int N;
	fscanf(f, "%d", &N);
	int** Graph = calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) {
		Graph[i] = calloc(N, sizeof(int));
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(f, "%d", &Graph[i][j]);
		}
	}

	mat_to_list(Graph, N);
	print_adj_list(N);
	printf("DFS: ");
	dfs(0);
	printf("\nNFS: ");
	bfs(0);
	fclose(f);


}