#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
	int coef;
	int expon;
	polyPointer next;

} polyNode;

polyPointer append(polyPointer h, int coef, int expon)
{

	polyPointer curr, p;
	curr = (polyPointer)(calloc(1, sizeof(polyNode)));
	curr->coef = coef;
	curr->expon = expon;
	curr->next = NULL;

	if (h == NULL)
	{
		h = curr;
	}
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

void print(polyPointer h)
{
	polyPointer p = h, q = h;
	int cnt = 0;
	while (q != NULL)
	{
		cnt++;
		q = q->next;
	}
	printf("%d", cnt);
	while (p != NULL)
	{
		printf(" %d %d", p->coef, p->expon);
		p = p->next;
	}
}

polyPointer padd(polyPointer poly1, polyPointer poly2)
{
	polyPointer p1, p2, p3 = NULL;
	int coef;
	p1 = poly1;
	p2 = poly2;
	while (p1 && p2)
	{
		if (p1->expon > p2->expon)
		{
			p3 = append(p3, p1->coef, p1->expon);
			p1 = p1->next;
		}
		else if (p1->expon == p2->expon)
		{
			coef = p1->coef + p2->coef;
			if (coef != 0)
				p3 = append(p3, coef, p1->expon);

			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			p3 = append(p3, p2->coef, p2->expon);
			p2 = p2->next;
		}
	}

	for (; p1; p1 = p1->next)
	{
		p3 = append(p3, p1->coef, p1->expon);
	}
	for (; p2; p2 = p2->next)
	{
		p3 = append(p3, p2->coef, p2->expon);
	}

	return p3;
}

void main()
{
	FILE *f1, *f2, *f3, *f4;
	polyPointer poly1 = NULL, poly2 = NULL, poly3 = NULL, tmp = NULL, result = NULL;

	int N, coef, expon, k = 0;

	f1 = fopen("a.txt", "r");
	f2 = fopen("b.txt", "r");
	f3 = fopen("c.txt", "r");
	f4 = fopen("k.txt", "r");

	fscanf(f1, "%d", &N);
	fscanf(f4, "%d", &k);

	for (int i = 0; i < N; i++)
	{
		fscanf(f1, "%d %d", &coef, &expon);
		coef *= k;
		poly1 = append(poly1, coef, expon);
	}

	fscanf(f2, "%d", &N);
	for (int i = 0; i < N; i++)
	{
		fscanf(f2, "%d %d", &coef, &expon);

		poly2 = append(poly2, coef, expon);
	}

	tmp = padd(poly1, poly2);
	fscanf(f3, "%d", &N);
	for (int i = 0; i < N; i++)
	{
		fscanf(f3, "%d %d", &coef, &expon);
		coef *= -1;
		poly3 = append(poly3, coef, expon);
	}

	result = padd(tmp, poly3);

	print(result);

	free(poly1);
	free(poly2);
	free(poly3);
	free(tmp);
	free(result);

	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}
