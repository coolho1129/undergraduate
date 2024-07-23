#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct listNode *listPointer;

typedef struct listNode
{
    int data;
    listPointer link;
} listNode;

listPointer first = NULL, second = NULL;

void insert(listPointer *ptr, int data)
{
    listPointer p, temp;

    temp = (listPointer)malloc(sizeof(listNode));

    temp->link = NULL;
    temp->data = data;

    if (*ptr == NULL)
        *ptr = temp;

    else
    {
        p = *ptr;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void concatenate(listPointer *first, listPointer *second)
{
    listPointer p1, p2;
    p1 = *first;
    p2 = *second;
    while (p1->link != NULL)
    {
        p1 = p1->link;
    }
    p1->link = p2;
}

void printList(listPointer ptr)
{
    for (; ptr; ptr = ptr->link)
        printf(" (%p,%d,%p) ", ptr, ptr->data, ptr->link);
}

listPointer invert(listPointer lead)
{
    listPointer middle, trail;
    middle = NULL;
    while (lead != NULL)
    {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return middle;
}

int main(void)
{
    FILE *f1, *f2;
    listNode input;
    f1 = fopen("input1.txt", "r");
    f2 = fopen("input2.txt", "r");

    while (fscanf(f1, "%d", &input.data) != EOF)
    {
        insert(&first, input.data);
    }

    while (fscanf(f2, "%d", &input.data) != EOF)
    {
        insert(&second, input.data);
    }
    printf("First:\n");
    printList(first);
    printf("\nSecond:\n");
    printList(second);
    concatenate(&first, &second);
    printf("\nConcatenate:\n");
    printList(first);
    printf("\nInvert:\n");
    printList(invert(first));

    free(first);
    free(second);
    fclose(f1);
    fclose(f2);

    return 0;
}