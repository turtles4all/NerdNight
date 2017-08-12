#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{

	pid_t pid;
	pid = getpid();
	printf("PID: %d\n", pid);
	char cmd[50];

	sprintf(cmd,"ls -l --color /proc/%d/fd", pid);
	
	printf("Executing command \"%s\"\n\n", cmd);
	
	system(cmd);
	
	return 0;
}
