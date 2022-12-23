#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define FALSE 0
#define TRUE 1
#define MAXSIZE 100
#define INF (INT_MAX/2)




int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;

	for (int i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;

}
void shortestPath(int v, int** cost, int distance[], int n, short int found[]) {

	int i, u, w;
	for (int i = 0; i < n; i++) {
		found[i] = FALSE;
		distance[i] = cost[v][i];

	}
	
	found[v] = TRUE;
	distance[v] = 0;

	for (int i = 0; i < n - 2; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
				}
			}
		}
	}
	for (w = 0; w < n; w++) {
		printf("%d ", distance[w]);
	}




}


void main() {

	FILE* f = fopen("input.txt", "r");
	int N, start, index = 0, input;
	fscanf(f, "%d %d", &N, &start);
	int* distance = calloc(N, sizeof(int));
	int* found = calloc(N, sizeof(int));
	int** cost = calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) {
		cost[i] = calloc(N, sizeof(int));
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(f, "%d", &input);
			if (input == 0) {
				cost[i][j] = INF;
			}
			else {
				cost[i][j] = input;
			}
		}
	}

	shortestPath(start, cost, distance, N, found);

	free(cost);
	free(distance);
	free(found);
	fclose(f);
}