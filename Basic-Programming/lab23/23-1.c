#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct linked_list
{

	int data;
	struct linked_list *next;
} NODE;

NODE *insertHead(NODE *h, int data)
{

	NODE *node;

	node = (NODE *)malloc(sizeof(NODE));

	node->data = data;

	node->next = h;
	h = node;

	return h;
}

void search_num(NODE *h, int search)
{
	NODE *p;
	p = h;
	while (p != NULL)
	{
		if (p->data == search)
		{
			printf("true");
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		printf("false");
}

void main()
{
	int search;
	NODE *h = NULL, input;
	for (;;)
	{
		scanf("%d", &input.data);
		if (input.data == 0)
			break;
		h = insertHead(h, input.data);
	}

	scanf("%d", &search);
	search_num(h, search);
}