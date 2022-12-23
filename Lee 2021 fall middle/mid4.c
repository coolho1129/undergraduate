#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int bitcount(int x);
void main()
{

    int x;

    for (;;)
    {

        scanf("%d", &x);
        if (x == -1)
        {
            break;
        }
        printf("%d\n", bitcount(x));
    }
}

int bitcount(int x)
{
    int cnt = 0;
    for (int i = 2; i <= 8; i += 2)
    {
        // printf("%d ", ((x & (1 << (i - 1))) ? 1 : 0));
        cnt += ((x & (1 << (i - 1))) ? 1 : 0);
    }
    return cnt;
}