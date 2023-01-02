#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4351) 
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef struct linked_list {

	int data;
	struct linked_list* next;
}NODE;

void printList(NODE* h) {

	NODE* p = h;

	while (p != NULL) {
	
		printf("%d ", p->data);
		p = p->next;
	
	}
	printf("\n");
}
NODE* insertSorted(NODE* h, int data);
int main()
{
	int i, data;
	NODE* header = NULL;
	 
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data);
		header = insertSorted(header, data);
	}
	printList(header);
	return 0;

}

NODE* insertSorted(NODE* h, int data)
{
	NODE *node,*p,*q;

	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	p = h,q=h;
	while (p != NULL)
	{
		if (p->data > data)
			break;
		
		q = p;
		p = p->next;
	}
	if (p == h) {
		node->next = h;
		h = node;
	}
	else {
		node->next = p;
		q->next = node;
	
	}
	return h;
}