#include <stdio.h>
#include <pthread.h>

struct primeTestRange
{
	int startN;
	int endN;
};

int N, totalCount = 0;
pthread_mutex_t count_lock;
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
	int count = 0;
	struct primeTestRange range;
	range = *(struct primeTestRange *)arg;

	for (int i = range.startN; i <= range.endN; i++)
	{
		if (isprime(i))
		{

			count++;
		}
	}
	pthread_mutex_lock(&count_lock);
	totalCount += count;
	pthread_mutex_unlock(&count_lock);

	printf("Thread is Done\n");
}

int main()
{
	int count = 0;
	int status;
	struct primeTestRange r1, r2;
	pthread_t thrd1, thrd2;
	printf("Enter a positive integer : ");
	scanf("%d", &N);

	//	printf("%d\n",N);
	r1.startN = 2;
	r1.endN = N / 2;
	r2.startN = N / 2 + 1;
	r2.endN = N;

	//	printf("1\n");
	pthread_create(&thrd1, NULL, prime_count, &r1);
	pthread_create(&thrd2, NULL, prime_count, &r2);
	//	printf("2\n");

	pthread_join(thrd1, &status);
	pthread_join(thrd2, &status);
	printf("The number of prime numbers is %d\n", totalCount);
}
