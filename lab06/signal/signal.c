#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void f(int signum){
	printf("KIMCHANHO\n");
}

int main(){
	void f(int);
	int i;
	signal(SIGINT,f);
	for(;;){
		printf("HELLO\n");
		sleep(1);
	}
}
