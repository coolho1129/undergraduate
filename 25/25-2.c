#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

void main()
{
	char operator[100] = {0};
	int a, b;
	for (;;)
	{
		scanf("%s %d %d", operator, & a, &b);

		if (strcmp(operator, "quit") == 0)
			break;
		else if (strcmp(operator, "plus") == 0)
			printf("%d\n", a + b);
		else if (strcmp(operator, "minus") == 0)
			printf("%d\n", a - b);
		else if (strcmp(operator, "divide") == 0)
		{
			if (b == 0)
				printf("Divide-by-Zero\n");
			else
				printf("%d\n", a / b);
		}
		else
			printf("Invalid Operator\n");
	}
}
