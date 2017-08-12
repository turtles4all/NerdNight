/*
 * ascii-to-int.c
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	
	int port;
	port = atoi(argv[1]);
	
	printf("\nPort number is : %d\n", port);
	
	return 0;
}

