#include <stdio.h>
#include <pthread.h>

int isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int main()
{
    int N;
    int count;

    printf("Enter a positive integer : ");
    scanf("%d", &N);
    count = 0;
    for (int i = 2; i <= N; i++)
        if (isPrime(i))
            count++;

    printf("The number of prime numbers is %d. \n", count);
}