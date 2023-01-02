#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct linked_list
{

	int data;
	struct linked_list *next;
};
typedef struct linked_list NODE;
typedef NODE *Link;

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

void increaseList(NODE *h)
{
	NODE *p;
	p = h;
	while (p != NULL)
	{
		p->data += 10;
		p = p->next;
	}
}
void printfList(NODE *h)
{
	NODE *p;
	p = h;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void main()
{
	NODE *h = NULL, input;
	for (;;)
	{
		scanf("%d", &input.data);
		if (input.data == 0)
			break;
		h = append(h, input.data);
	}

	increaseList(h);
	printfList(h);
}