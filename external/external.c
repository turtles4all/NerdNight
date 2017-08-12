/*
 * extern is being used to declare count in the second file, where as it
 * has its definition in the first file, main.c
 */

#include <stdio.h>
 
extern int count;
 
void write_extern(void) {
   printf("count is %d\n", count);
}
