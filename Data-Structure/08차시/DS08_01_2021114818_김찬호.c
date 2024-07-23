#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int stack[101];
int capacity = -1;
int top = -1;
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

typedef enum
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

precedence getToken(char symbol)
{
    switch (symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '/':
        return divide;
    case '*':
        return times;
    case '%':
        return mod;
    case ' ':
        return eos;
    default:
        return operand;
    }
}

char changeToken(precedence token)
{
    switch (token)
    {
    case lparen:
        return '(';
    case rparen:
        return ')';
    case plus:
        return '+';
    case minus:
        return '-';
    case divide:
        return '/';
    case times:
        return '*';
    case mod:
        return '%';
    default:
        return 0;
    }
}

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}

void Posfix(char *infix, char *postfix)
{

    int inow = 0;
    int pnow = 0;
    int len = strlen(infix);
    push(eos);

    while (inow < len)
    {
        char item = infix[inow++];
        precedence token = getToken(item);

        if (token == operand)
            postfix[pnow++] = item;
        else if (token == rparen)
        {
            while (stack[top] != lparen)
                postfix[pnow++] = changeToken(pop());
            pop();
        }
        else
        {
            while (isp[stack[top]] >= icp[token])
                postfix[pnow++] = changeToken(pop());
            push(token);
        }
    }

    while (stack[top] != eos)
    {
        char tmp = changeToken(pop());
        postfix[pnow++] = tmp;
    }
    pop();
}

int eval(char *postfix)
{
    char token, op1, op2;
    for (int i = 0; postfix[i] != 0; i++)
    {
        token = postfix[i];
        if (getToken(token) == operand)
            push(token - '0');
        else
        {
            op1 = pop();
            op2 = pop();
            switch (token)
            {
            case '*':
                push(op2 * op1);
                break;
            case '/':
                push(op2 / op1);
                break;
            case '%':
                push(op2 % op1);
                break;
            case '+':
                push(op2 + op1);
                break;
            case '-':
                push(op2 - op1);
            }
        }
    }
    return pop();
}

int main(void)
{
    FILE *f;
    char infix[101] = {0};
    char postfix[101] = {0};

    f = fopen("input.txt", "r");
    fscanf(f, "%s", infix);
    Posfix(infix, postfix);

    printf("Postfix:");
    printf("%s", postfix);
    printf("\nResult:");
    printf("%d", eval(postfix));
    fclose(f);
    return 0;
}