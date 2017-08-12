/*
 * mem-copy-section.c
 *
 * Example showing how to reference a section of an array and transfer 
 * it to another block of memory.
 *
 */

#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char buffer[20] = "AAAABBBBAAAA";
	char copy[20];
	memcpy(&copy, buffer+4, 4 * sizeof(char));
	printf("%s\n", copy);
	return 0;
}

