#include <stdio.h>
#include <sys/syscall.h>

#define SYSCALL_NUM 451

int main()
{
	long int res = syscall(SYSCALL_NUM);
	printf("sys_proj1call returned: %ld\n", res);
	return 0;
}
