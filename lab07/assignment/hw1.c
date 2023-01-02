#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
int cnt = 3;

void print()
{
	time_t ct;
	struct tm tm;
	ct = time(NULL);
	tm = *localtime(&ct);
	printf("KIMCHANHO: ");
	printf("%d-%d-%d hour: %d, min : %d, sec: %d\n",
		   tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
		   tm.tm_min, tm.tm_sec);
}

void my_sig_handler(int signnum)
{

	print();
	cnt--;
	alarm(5);
}

int main()
{
	print();
	signal(SIGALRM, my_sig_handler);
	alarm(5);

	while (cnt)
	{
		// printf("HELLO\n");
		sleep(1);
	}
	print();
	printf("program is finshed\n");

	return 0;
}
