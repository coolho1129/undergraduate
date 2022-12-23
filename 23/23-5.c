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
int findMIN(NODE *head)
{
	NODE *p;
	p = head;
	int min = p->data;

	while (p != NULL)
	{
		if (min > p->data)
			min = p->data;
		p = p->next;
	}
	return min;
}
int findMAX(NODE *head)
{
	NODE *p;
	p = head;
	int max = p->data;

	while (p != NULL)
	{
		if (max < p->data)
			max = p->data;
		p = p->next;
	}
	return max;
}

int sumList(NODE *head)
{
	int sum = 0;
	NODE *p;
	p = head;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

NODE *appendList(NODE *h1, NODE *h2)
{
	NODE *p1, *p2;
	p1 = h1;
	p2 = h2;
	while (p1->next != NULL)
	{
		p1 = p1->next;
	}
	p1->next = p2;

	return h1;
}
void tranverseList(NODE *h)
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
	NODE *h1 = NULL, *h2 = NULL, input;
	for (;;)
	{
		scanf("%d", &input.data);
		if (input.data == 0)
			break;
		h1 = append(h1, input.data);
	}
	for (;;)
	{
		scanf("%d", &input.data);
		if (input.data == 0)
			break;
		h2 = append(h2, input.data);
	}

	tranverseList(appendList(h1, h2));
}