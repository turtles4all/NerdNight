// function declaration
#include <stdio.h>

int func(void);

int main(void) {

   // function call
   int i = func();
   printf("The value of i is %d \n", i);
   
   return 0;
}

// function definition
int func(void) {
   return 42;
}
