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

NODE *append(NODE *h, int data);
NODE *insertSorted(NODE *h, int data);
NODE *deleteNode(NODE *h, int data);
void printList(NODE *h);
int findmedian(NODE *h, int count);

void main()
{
	int i, data, median, cnt = 0;
	NODE *header1 = NULL, *header2 = NULL;
	for (;;)
	{
		scanf("%d", &data);
		if (data == 0)
			break;
		cnt++;
		header1 = append(header1, data);
		header2 = insertSorted(header2, data);
	}
	median = findmedian(header1, cnt);
	printf("median: %d\n", median);
	deleteNode(header2, median);
	printList(header2);
}

NODE *append(NODE *h, int data)
{

	NODE *p, *curr;

	curr = (NODE *)calloc(1, sizeof(NODE));
	curr->next = NULL;
	curr->data = data;

	if (h == NULL)
		h = curr;

	else
	{

		p = h;
		while (p->next != NULL)
		{
			p = p->next;
		}

		p->next = curr;
	}
	return h;
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

void printList(NODE *h)
{

	NODE *p = h;

	printf("list: ");
	while (p != NULL)
	{

		printf("%d ", p->data);

		p = p->next;
	}
	printf("\n");
}

int findmedian(NODE *h, int cnt)
{
	NODE *p;
	p = h;
	int middle, median = 0, i;
	middle = (cnt / 2) + 1;

	for (i = 0; i < middle; i++)
	{
		median = p->data;
		p = p->next;
	}
	return median;
}
