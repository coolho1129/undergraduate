#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef struct linked_list
{
    int data;
    int cnt;
    struct linked_list *next;
} NODE;

NODE *insertNoDuplicate(NODE *h, int data)
{
    NODE *node, *p, *q;

    node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node->cnt = 1;

    p = h, q = h;

    while (p != NULL)
    {

        if (p->data > data)
        {

            break;
        }
        if (p->data == data)
        {
            p->cnt++;
            return h;
        }
        q = p;
        p = p->next;
    }

    if (p == h)
    {
        node->next = h;
        h = node;
    }
    else
    {
        node->next = p;
        q->next = node;
    }
    return h;
}

void printList(NODE *h)
{

    NODE *p = h;

    while (p != NULL)
    {
        printf("%d(%d) ", p->data, p->cnt);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    int data;
    NODE *header = NULL;

    for (;;)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        header = insertNoDuplicate(header, data);
    }
    printList(header);
}