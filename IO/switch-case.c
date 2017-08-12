/*
 * switch-case.c
 * 
 */


#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	
	int poop = 1;
	
	switch( poop ){
		case 0 :
			printf("Stuff 0");
			break;
		case 1 :
			printf("Stuff 1");
			break;
		case 2 :
			printf("Stuff 2");
			break;
	}
	
	write(STDOUT_FILENO	, "\n", 1);
	
	return 0;
}

