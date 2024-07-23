#include <stdio.h>

void printLess(int n)
{
    if (n <= 0)
    {
        return;
    }
    printLess(n - 1);
    printf("%d ", n);
    printLess(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    printLess(n);

    return 0;
}