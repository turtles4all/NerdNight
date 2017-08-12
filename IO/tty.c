


#include <stdio.h>
#include <unistd.h>

#include <dirent.h>

int main(int argc, char **argv)
{
	
	pid_t pid;
	pid = getpid();
	
	printf("PID: %d\nFD's:\n", pid);
	char path[30];
	sprintf(path,"/proc/%d/fd", pid);
	
	DIR *d;
    struct dirent *dir;
    
    d = opendir(path);
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

