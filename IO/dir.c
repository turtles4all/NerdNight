


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char **argv)
{

	pid_t pid;
	pid = getpid();
	printf("PID: %d\nFD's:\n", pid);
	char cmd[30];
	
	sprintf(cmd,"/proc/%d/fd", pid);
	DIR *d;
    struct dirent *dir;
    d = opendir(cmd);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }

	
	
	return 0;
}

