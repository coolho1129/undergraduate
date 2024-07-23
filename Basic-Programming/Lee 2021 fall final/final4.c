#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

/*
    1학기 기말고사 숫자 오름차수 정렬하기와 중복된 값 개수 세기에서 문자 오름차순 정렬하기와 중복된 개수 세기로 바꿔서 출제됨
*/

typedef struct linked_list
{
    char data[100];
    int cnt;
    struct linked_list *next;
} NODE;

NODE *insertNoDuplicate(NODE *h, char data[])
{
    NODE *node, *p, *q;

    node = (NODE *)malloc(sizeof(NODE));
    strcpy(node->data, data);
    node->cnt = 1;

    p = h, q = h;

    while (p != NULL)
    {

        if (strcmp(p->data, data) > 0)
        {

            break;
        }
        else if (strcmp(p->data, data) == 0)
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
        printf("%s(%d) ", p->data, p->cnt);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    char data[100] = {0};
    NODE *header = NULL;

    for (;;)
    {
        scanf("%s", data);
        if (strcmp(data, "quit") == 0)
            break;
        header = insertNoDuplicate(header, data);
    }
    printList(header);
}