#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef char element;
typedef struct
{

	element *data;
	int top;
	int capacity;

} stack;

void init_stack(stack *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}
void delete(stack *s)
{
	free(s);
}

int is_empty(stack *s)
{
	return (s->top == -1);
}

int is_full(stack *s)
{
	return (s->top == (s->capacity - 1));
}

void push(stack *s, element item)
{
	if (is_full(&s))
	{
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}

	s->data[++(s->top)] = item;
}

element pop(stack *s)
{
	if (is_empty(&s))
	{
		printf("스택 공백 에러");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(stack *s)
{
	if (is_empty(&s))
	{
		printf("스택 공백에러");
		exit(1);
	}
	else
		return s->data[s->top];
}

int prior(char op)
{
	switch (op)
	{

	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	}
	return -1;
}

void infix_to_podtfix(char str[], char *postfix)
{
	int len = strlen(str), cnt = 0;
	char ch, top_op;
	stack s;

	init_stack(&s);

	for (int i = 0; i < len; i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while (!is_empty(&s) && (prior(peek(&s)) >= prior(ch)))
				postfix[cnt++] = pop(&s);

			push(&s, ch);
			break;

		case '(':
			push(&s, ch);
			break;

		case ')':
			top_op = pop(&s);
			while (top_op != '(')
			{
				postfix[cnt++] = top_op;
				top_op = pop(&s);
			}
			break;

		default:
			postfix[cnt++] = ch;
			break;
		}
	}
	while (!is_empty(&s))
		postfix[cnt++] = pop(&s);
}

int eval(char str[])
{
	int num1, num2, len = strlen(str), value;
	char ch;
	stack s;

	init_stack(&s);
	for (int i = 0; i < len; i++)
	{
		ch = str[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%')
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
			}
		}
	}
	return pop(&s);
}

int main(void)
{
	FILE *f;
	char infix[101] = {0};
	char postfix[101] = {0};

	f = fopen("input.txt", "r");
	fscanf(f, "%s", infix);

	printf("Postfix:");
	infix_to_podtfix(infix, postfix);
	printf("%s", postfix);
	printf("\nResult:");
	printf("%d", eval(postfix));
	fclose(f);
	return 0;
}