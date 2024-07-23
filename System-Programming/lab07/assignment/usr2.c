 #include <stdio.h>
 #include <sys/types.h>
 #include <signal.h>
 #include <unistd.h> 
 int yourpid;
 int mypid;
  
 void my_sig_handler (int signum){
        printf("USER2 send USER1 signal\n"); 
	kill(yourpid,SIGUSR1);
 	sleep(1);
  	kill(mypid,SIGKILL);
}
 
  int main (){
          
	  signal(SIGUSR2,my_sig_handler);
          
	  mypid = getpid();
          printf ("mypid = %d \n", mypid);
          scanf("%d",&yourpid);
          
	  printf("Waiting signal from USER1\n");
	  for(;;){
		printf("waiting...\n");
		sleep(3);
	 };
 	
	  return 0;
 
  }
