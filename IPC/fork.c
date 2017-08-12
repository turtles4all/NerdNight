#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
  
int main(int argc, char **argv)
{
    
    
	pid_t pid=fork();
	if (pid==0){ //child
		int i;
		for (i=0; i<8; i=i+1){
		printf ("I am a child pid: %d\n", getpid());
		sleep(2);}
		
	}
	
	if (pid >0 ){ //Parent 
	int looping = 0;
	while (looping == 1){
		printf("I am the parrent pid: %d\n", getpid());
		sleep(2);
		}
	printf("waiting for Child to finish\n");
	sleep(900);
}
	
//	wait(NULL);
	return 0;
}

 
