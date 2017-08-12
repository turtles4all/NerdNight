#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>
void *pthread(int *arg);

int main(int argc, char *argv[]){




    fd_set read_fds;  //file descriptor list for select()

    int fdmax = sizeof(read_fds);        // maximum file descriptor number

    FD_ZERO(&read_fds);
    // add FD's to the master set
    FD_SET(STDIN_FILENO, &read_fds);
    printf("size of read_fds %d", fdmax);
        if (select(1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(4);
        }

    
    
    
	return 0;
}

/*
void *pthread(int *arg){
	int i = 0;

	for (i; i<arg; i++){
		printf("%n", &i);
		sleep(1);
	}
	return 0;
}
*/
