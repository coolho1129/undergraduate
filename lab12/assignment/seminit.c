#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    sem_t *sem;

    sem = sem_open("testsem", O_CREAT, 0666, 1); // 초기값 1로 초기화
    printf("sem = %p\n", sem);
}
