#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
	int top;
	int capacity;
	int *data;
} stack;

init_stack(stack *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (int *)calloc(s->capacity, sizeof(int));
}

int isFull(stack *s)
{
	return (s->top == (s->capacity - 1));
}

int isEmpty(stack *s)
{
	return (s->top == -1);
}

void push(stack *s, int item)
{
	// printf("push");
	if (isFull(&s))
	{
		s->capacity *= 2;
		s->data = realloc(s->data, sizeof(int) * s->capacity);
	}
	s->data[++(s->top)] = item;
}

int pop(stack *s)
{
	if (isEmpty(&s))
	{
		printf("Stack is empty");
		exit(1);
	}

	return s->data[(s->top)--];
}

int peek(stack *s)
{
	if (isEmpty(&s))
	{
		printf("Stack is empty");
		exit(1);
	}

	return s->data[(s->top)];
}

int eval(char postfix[])
{
	// printf("2");
	stack s;
	char ch;
	int len = strlen(postfix), num1 = 0, num2 = 0, value = 0, result = 0;
	init_stack(&s);
	for (int i = 0; i < len; i++)
	{
		ch = postfix[i];

		if ('0' <= ch && ch <= '9')
		{
			value = ch - '0';
			push(&s, value);
		}

		else
		{
			num2 = pop(&s);
			num1 = pop(&s);
			switch (ch)
			{

			case '+':
				push(&s, num1 + num2);
				break;

			case '-':
				push(&s, num1 - num2);
				break;

			case '*':
				push(&s, num1 * num2);
				break;

			case '/':
				push(&s, num1 / num2);
				break;

			case '%':
				push(&s, num1 % num2);
				break;

			case '^':
				if (num2 != 0)
					result = (int)(pow(num1, num2));
				else
					result = 1;
				push(&s, result);
				break;

			case '~':
				push(&s, abs(num1 - num2));
				break;

			case '=':
				if (num1 == num2)
					result = 1;
				else
					result = 0;
				push(&s, result);
				break;
			}
		}
	}
	return pop(&s);
}

void main()
{
	FILE *f;
	char postfix[101] = {0};

	f = fopen("input.txt", "r");
	fscanf(f, "%s", postfix);
	printf("%d", eval(postfix));

	fclose(f);
}
