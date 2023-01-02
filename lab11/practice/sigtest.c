#include <stdio.h>
#include <signal.h>

int cnt=0;
int pnum;
int pids[10];
void my_sig_handler(int signum){
	//printf("signum = %d \n",signum);
	cnt++;
}

void barrier(){
	int i;

	for(i=0;i<pnum;i++)
		kill(pids[i],SIGUSR1);
	
	while(cnt<pnum-1){
		pause();
	}
	cnt=0;
}

void work(int secs){

	int i,j,k;
	int sum=0;
	for(i=0;i<secs;i++){
		for(j=0;j<100;j++){
			for(k=0;k<1000000;k++)
				sum++;
		}

	}
}

int main(){
	int work_t;
	printf("pid = %d \n",getpid());
	signal(SIGUSR1,my_sig_handler);
	printf("Enter the number of process : " );
	scanf("%d",&pnum);
	srand(time(NULL));
	
	for(int i=0;i<pnum-1;i++){
		printf("Enter %d process id: ",i);
		scanf("%d",&pids[i]);
	}

	while(1){
		work_t=rand()%10+1;
		printf("Working for %d secs... \n",work_t);
		work (work_t);
		printf("		Done.\n");
		barrier();
		printf("End of barrier \n");

	}
}
