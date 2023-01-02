#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct PrimeTestRange
{
    int startN;
    int endN;
};

int isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int N;
int total_count = 0;
pthread_mutex_t count_lock;

void *prime_count(void *arg)
{
    int count = 0;
    struct PrimeTestRange range;
    range = *(struct PrimeTestRange *)arg;

    for (int i = range.startN; i <= range.endN; i++)
        if (isPrime(i))
        {
            count++;
        }

    pthread_mutex_lock(&count_lock);
    printf("Thread is done.\n");
}
int main()
{
    int count;
    int status;
    struct PrimeTestRange r1, r2;

    pthread_t thrd1, thrd2;

    printf("Enter a positive integer : ");
    scanf("%d", &N);

    r1.startN = 2;
    r1.endN = N / 2;
    r2.startN = N / 2 + 1;
    r2.endN = N;

    pthread_create(&thrd1, NULL, prime_count, &r1);
    pthread_create(&thrd2, NULL, prime_count, &r2);

    pthread_join(thrd1, &status);
    pthread_join(thrd2, &status);
    printf("The number of prime numbers is %d. \n", total_count);
}