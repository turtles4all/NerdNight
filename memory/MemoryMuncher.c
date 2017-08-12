/*
 * 
 * MemoryMuncher.c
 * 
 * This program has no intended use. Memory Muncher was written as a POC
 * to show the effects of leaking memory from the system. Memory leaked
 * from using Memory Muncher will be unusable until after the system
 * reboots. 
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
int power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }

int main(int argc, char **argv)
{
	if( (argc < 3 ) || (argc > 3) ) {
		fprintf(stderr, 
"\
* This program has no intended use.\n\
* Memory Muncher was written as a POC to show the effects of\n\
* leaking memory from the system that chould be caused by the\n\
* programmer allocating memory but forgetting to free the\n\
* memory.\n\
* Memory leaked from using Memory Muncher will be unusable until\n\
* after the system reboots. \n\n\
Usage is MemoryMuncher 'Block Size' 'Ammount \
Multiplyer i.e. B, K, M, G'\n\n'MemoryMuncher 1024 M ' will leak\
1GB from the system\n");
		exit(1);
	}
	int bs;
	bs = atoi(argv[1]);
	
	char *m = argv[2];
	long int mult;
	unsigned long long int tot;
	switch (*m){
		case 'B' :
			mult = 1;
			break;
		case 'K' :
			mult = 1024;
			break;
		case 'M' :
			mult = power(1024, 2);
			break;
		case 'G' :
			mult = power(1024, 3);
			break;		
		default :
			fprintf(stderr, "Invalid Multuplyer\n");
			exit(1);
		}
	tot = bs*mult;
	fprintf(stderr, "Total bytes that will be lost = %lld\n", tot);
	fprintf(stderr, "Are you sure you want to leak %d%c from the\
system?\n(Y or N):",bs, *m);
	char a = getchar(); 
	char *leak;
	if ((a == 'Y') || (a == 'y')){
		
		fprintf(stderr,"Your wish is my command!\n");
		leak =  malloc(tot * sizeof(char));
		
		
		for(int i = 0; i < tot; i++){
			leak[i] = 'A';
		}
		fprintf(stderr,"It has been Done!\n");
		pid_t pid = getpid();
		kill(pid, SIGKILL);
	
	}
	

	return 0;
}

