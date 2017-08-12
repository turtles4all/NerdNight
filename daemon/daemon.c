/*
 * 
 * The begining of a daemon
 * 
 */

#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
	
	pid_t pid, sid;
	
	//fork the process
	pid = fork();
	if (pid < 0){
		exit(1);
	}
	//let the parent process die
	if (pid > 0){ 
		exit(0);
	}
	
	//gain new sid so that the shild is no longer an orphan 
	umask(0);
	sid = setsid();
	if (sid < 0){         
		exit(0);
	}
	if ((chdir("/")) < 0){
		exit(0);
	}
	//close IO 
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	int looping = 1;
	
	//start the daemon loop
	while(looping){
		// do some daemon things... or just goto sleep
		sleep(30);
	}
	
}
