#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node *nodePointer;
typedef struct node
{
    int data;
    nodePointer link;
} node;

int main()
{
    FILE *fp = fopen("input.txt", "r");

    int N, M, i, j, k;
    int *out;
    nodePointer *seq;
    nodePointer head1, head2, top;

    fscanf(fp, "%d", &N);
    fscanf(fp, "%d", &M);

    seq = (nodePointer *)calloc(N, sizeof(nodePointer));
    out = (int *)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
    {
        out[i] = TRUE;
    }

    for (k = 0; k < M; k++)
    {
        fscanf(fp, "%d %d", &i, &j);

        head1 = (nodePointer)malloc(sizeof(node));
        head1->data = j;
        head1->link = seq[i];
        seq[i] = head1;

        head1 = (nodePointer)malloc(sizeof(node));
        head1->data = i;
        head1->link = seq[j];
        seq[j] = head1;
    }

    for (i = 0; i < N; i++)
    {
        if (out[i] == TRUE)
        {
            printf("\nNew class: %d ", i);
            out[i] = FALSE;
            head1 = seq[i];
            top = NULL;
            for (;;)
            {
                while (head1)
                {
                    j = head1->data;
                    if (out[j])
                    {
                        printf("%d ", j);
                        out[j] = FALSE;
                        head2 = head1->link;
                        head1->link = top;
                        top = head1;
                        head1 = head2;
                    }
                    else
                    {
                        head1 = head1->link;
                    }
                }
                if (top == NULL)
                    break;
                head1 = seq[top->data];
                top = top->link;
            }
        }
    }
    return 0;
}