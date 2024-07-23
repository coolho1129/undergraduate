#include <stdio.h>
#include <pthread.h>

int N, totalCount = 0;
int testNum = 2;
pthread_mutex_t count_lock, test_lock;

int isprime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void *prime_count(void *arg)
{
    int count = 0, num;
    while (testNum <= N)
    {
        pthread_mutex_lock(&test_lock);
        num = testNum;
        testNum++;
        pthread_mutex_unlock(&test_lock);

        if (isprime(num))
        {
            pthread_mutex_lock(&count_lock);
            totalCount++;
            pthread_mutex_unlock(&count_lock);
        }
    }

    printf("Thread is Done\n");
}

int main()
{
    int count = 0;
    int status;
    pthread_t thrd1, thrd2;
    printf("Enter a positive integer : ");
    scanf("%d", &N);

    pthread_create(&thrd1, NULL, prime_count, NULL);
    pthread_create(&thrd2, NULL, prime_count, NULL);

    pthread_join(thrd1, &status);
    pthread_join(thrd2, &status);
    printf("The number of prime numbers is %d\n", totalCount);
}
