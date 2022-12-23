#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n==MAX_ELEMENTS -1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
}element;

typedef struct stack {

	int top;
	int data[MAX_ELEMENTS];

}stack;

void init_stack(stack *s) {
	s->top = -1;
	
}
void add(stack* s, int item ) {
	if (s->top == MAX_ELEMENTS - 1) {
		fprintf(stderr, "The stack is full.\n ");
		exit(EXIT_FAILURE);
	}
	s->data[++(s->top)] = item;

}
int delete(stack *s) {

	if (s->top == - 1) {
		fprintf(stderr, "The stack is empty.\n ");
		exit(EXIT_FAILURE);
	}
	return s->data[(s->top)--];
}

int isempty(stack *s){
	return s->top == -1;
}
element heap[MAX_ELEMENTS];

void push(element item, int* n) {
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr,"The heap is full.\n ");
		exit(EXIT_FAILURE);
	}
	i = ++(*n);

	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
	
}

element pop(int* n) {
	element item, temp;
	int parent, child;

	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty.\n ");
		exit(EXIT_FAILURE);
	}

	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;

	while (child <= *n) {
	
		
		
			if ((child < *n) && heap[child].key < heap[child + 1].key) {
				child++;
			}
			
			if (temp.key >= heap[child].key) {
				break;
			}
			
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		
		
		
		
		
		
	
	}
	heap[parent] = temp;
	return item;
}

void levelorder(int n) {
	printf("Level order: ");
	for (int i = 1; i <= n; i++) {
			printf("%d ", heap[i].key);

	}
	printf("\n");
}
void inorder(int n) {
	stack s;
	init_stack(&s);
	int index = 1;
	printf("Inorder: ");

	for (;;) {
		
			
		while (index <= n) {
			add(&s, index);
			index *= 2;
		}
		
		
		if (isempty(&s))
			break;
		
		index = delete(&s);

		printf("%d ", heap[index].key);
		index = 2 * index + 1;
		
	
	
	}
	printf("\n");
}




void main() {

	int n = 0;
	FILE* f = fopen("input.txt", "r");
	int i = 0;
	element item;
	while (fscanf(f, "%d", &item.key) != EOF) {

		push(item, &n);
	}
	levelorder(n);
	inorder(n);
	pop(&n);
	
	levelorder(n);
	inorder(n);
	pop(&n);
	
	levelorder(n);
	inorder(n);

	

}
















