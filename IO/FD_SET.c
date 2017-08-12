#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
/*

FD_SET(int fd, fd_set *set);
Add fd to the set.

FD_CLR(int fd, fd_set *set);
Remove fd from the set.

FD_ISSET(int fd, fd_set *set);
Return true if fd is in the set.

FD_ZERO(fd_set *set);

*/
struct _toggles{
	int quit;
}toggles;

void init_toggles(){
	char Q = 'Q';
	toggles.quit = atoi(&Q);
}


int main(void) {
    fd_set rfds;
	struct timeval tv;
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	int retval;
	char buffer[255];
   /* Watch stdin (fd 0) to see when it has input. */
   FD_ZERO(&rfds);
   

   /* Wait up to five seconds. */
  
   tv.tv_usec = 0;
	int looping = 1;

	while(looping){
		memset(&buffer, 0, sizeof(buffer));
		tv.tv_sec = 5;
		FD_SET(0, &rfds);
		retval = select(1, &rfds, NULL, NULL, &tv);
	   /* Don't rely on the value of tv now! */
		if (retval == -1)
		{
		   perror("select()");
		}
		
		else if(retval && (FD_ISSET(STDIN_FILENO, &rfds))){
			printf("Data is available now.\n");
			read(STDIN_FILENO, &buffer, sizeof(STDIN_FILENO));
			printf("Input was: %s", buffer);

		}
		
		int n = strcmp(buffer, "quit");
		printf("cmp = : %d\n", n);
		if( !n ){
			printf("QUIT!");
			exit(0);
			
		}
	} // while
   exit(EXIT_SUCCESS);
}
