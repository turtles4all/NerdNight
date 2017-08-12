/*
 * Passing to and from functions
 */
#include <stdio.h>

int func(int a, int b);

int main(void) {

   int a = 5;
   int b = 6;
   
   //Pass a and b to func
   int i = func(a, b);
   
   printf("The value of i is %d \n", i);
   
   return 0;
}

// function definition
int func(int a, int b) {
	int i = a * b;
	return i;
}

