#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct linked_list
{

	double data;
	struct linked_list *next;
} NODE;

NODE *insertHead(NODE *h, double data)
{

	NODE *node;

	node = (NODE *)malloc(sizeof(NODE));
	node->data = data;
	node->next = h;
	h = node;

	return h;
}
printfMinMax(NODE *h)
{
	double min, max;
	NODE *p;
	p = h;
	min = p->data;
	max = p->data;
	while (p != NULL)
	{
		if (min > p->data)
			min = p->data;
		if (max < p->data)
			max = p->data;

		p = p->next;
	}

	printf("min:%0.1lf\n", min);
	printf("max:%0.1lf", max);
}

void main()
{

	int i, n;
	double data;
	NODE *header = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &data);
		header = insertHead(header, data);
	}
	printfMinMax(header);
}