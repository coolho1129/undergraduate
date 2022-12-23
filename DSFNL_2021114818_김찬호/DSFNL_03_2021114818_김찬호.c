#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWAP(a,b,t){t=a;a=b;b=t;}
#define MAX 10000
#define HEAP_FULL(n)(n==MAX-1)
#define  HEAP_EMPTY(n)(!n)

typedef struct element {
	int key;
}element;
element heap[MAX];

void push(element item, int* n) {
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "THE HEAP IS FULL");
		exit(EXIT_FAILURE);
	}

	i = ++(*n);
	while (i != 1 && item.key < heap[i / 2].key) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;

}

int getheight(int index) {
	int left = 0, right = 0;
	if (heap[2 * index].key) {

		left += getheight(2 * index);
	}
	else if (heap[2 * index + 1].key)
		right += getheight(2 * index + 1);


	return 1 + ((left >= right) ? left : right);

}

int count_leaf(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (heap[2 * i].key == 0 && heap[2 * i + 1].key == 0) {
			count++;
		}
	}
	return count;

}
void levelorder(int n) {
	printf("Level Order: ");
	for (int i = 1; i <= n; i++) {
		printf("%d ", heap[i].key);
	}
	puts("");
}
int main() {
	FILE* f = fopen("input.txt", "r");
	int n = 0;
	element item;
	while (fscanf(f, "%d", &item.key) != EOF) {
		push(item, &n);
	}

	levelorder(n);
	//printf("\n%d", n);
	printf("Height: %d\n", getheight(1));
	count_leaf(getheight(1));
	printf("Leaf: %d", count_leaf(n));

}

