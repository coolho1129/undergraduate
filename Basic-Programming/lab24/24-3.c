#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef struct linked_list
{

	int data;
	struct linked_list *next;
} NODE;

void printList(NODE *h)
{

	NODE *p = h;

	while (p != NULL)
	{

		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
NODE *insertSorted(NODE *h, int data);
NODE *insertNoDuplicate(NODE *h, int data);
NODE *deleteNode(NODE *h, int data);

void main()
{
	int i, data;
	NODE *header = NULL;

	for (i = 0;; i++)
	{
		scanf("%d", &data);
		if (data == 0)
			break;
		header = insertNoDuplicate(header, data);
	}
	scanf("%d", &data);
	header = deleteNode(header, data);
	printList(header);
}

NODE *insertSorted(NODE *h, int data)
{
	NODE *node, *p, *q;

	node = (NODE *)malloc(sizeof(NODE));
	node->data = data;
	p = h, q = h;
	while (p != NULL)
	{
		if (p->data > data)
			break;

		q = p;
		p = p->next;
	}
	if (p == h)
	{
		node->next = h;
		h = node;
	}
	else
	{
		node->next = p;
		q->next = node;
	}
	return h;
}

NODE *insertNoDuplicate(NODE *h, int data)
{
	NODE *node, *p, *q;

	node = (NODE *)malloc(sizeof(NODE));
	node->data = data;

	p = h, q = h;
	while (p != NULL)
	{
		if (p->data > data)
			break;

		if (p->data == data)
			return h;
		q = p;
		p = p->next;
	}

	if (p == h)
	{
		node->next = h;
		h = node;
	}
	else
	{
		node->next = p;
		q->next = node;
	}
	return h;
}

NODE *deleteNode(NODE *h, int data)
{
	NODE *p, *q;
	p = h, q = h;
	while (p != NULL)
	{
		if (p->data == data)
		{
			break;
		}
		if (p->data > data)
			return h;
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return h;
	else if (p == h)
	{
		h = h->next;
		free(p);
		return h;
	}
	else
	{
		q->next = p->next;
		free(p);
		return h;
	}
}