/*
 * Custom-Error.c
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WARNING 0
#define ERROR 1
#define FATAL -1

int error(char *error_message, int error_level) {
	char *level;
	
	switch(error_level){
		
		case -1:
			level = "[!!] FATAL \t:";
			break;
		case 0:
			level = "[!!] WARNING \t:";
			break;
		case 1:
			level = "[!!] ERROR \t:";
			break;
			
		default:
			level = "[!!] Issue :";
			
		}
		
	fprintf(stderr, "%s %s\n", level, error_message);
	
	if( error_level == -1){
		exit(-1);
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	error("Custom Error Message, Warning", WARNING);
	error("Custom Error Message, Error", ERROR);
	error("Custom Error Message, Fatal", FATAL);
	
	
	return 0;
}

