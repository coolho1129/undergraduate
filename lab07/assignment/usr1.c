#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int yourpid;
int mypid;

void my_sig_handler (int signum){
	sleep(1);
        kill(mypid, SIGKILL);
	
}

int main (){
	signal(SIGUSR1,my_sig_handler);
	
	mypid = getpid ();
	printf ("mypid = %d \n", mypid);
	scanf("%d",&yourpid);
	
	printf("USER1 send USER2 signal\n");
	printf("wating signal from USER2\n");
	
	kill(yourpid, SIGUSR2);
	
	for(;;){
		printf("waiting...\n");
		sleep(3);
	}

	return 0;

}
