#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <math.h>
#define MAX_TERMS 1001

typedef struct
{
	float coef;
	int expon;


}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

char compare(int a, int b)
{
	if (a > b)
		return '>';
	else if (a < b)
		return '<';
	else
		return '=';

}

void attach(float coef, int expon) {

	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many term in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void polyadd(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {

	*Cs = avail;
	while (As <= Ae && Bs <= Be) {
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>':
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;
		case '<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		case '=':
			attach(terms[As].coef + terms[Bs].coef, terms[Bs].expon);
			As++;
			Bs++;
			break;
		}

	}
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

int main()
{
	FILE* f1, * f2;
	f1 = fopen("a.txt", "r");
	f2 = fopen("b.txt", "r");
	int As = 0, Ae, Bs, Be, Ce, Cs, N1, N2, cnt = 0;
	float coef = 0;


	fscanf(f1, "%d", &N1);

	for (int i = 0; i < N1; i++) {
		fscanf(f1, "%f %d", &terms[i].coef, &terms[i].expon);
		cnt++;
	}
	Ae = cnt - 1;

	Bs = Ae + 1;

	fscanf(f2, "%d", &N2);

	for (int i = Bs; i < Bs + N2; i++) {
		fscanf(f2, "%f %d", &terms[i].coef, &terms[i].expon);
		cnt++;
	}

	Be = cnt - 1;
	avail = cnt;

	polyadd(As, Ae, Bs, Be, &Cs, &Ce);

	for (int i = Cs; i <= Ce; i++) {
		printf("%f", terms[i].coef);

		if (terms[i].expon != 0)
			printf("x^%d", terms[i].expon);
		if (i != Ce)
			printf(" + ");


	}

	fclose(f1);
	fclose(f2);

}