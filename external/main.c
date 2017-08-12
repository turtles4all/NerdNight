/*
 *The extern modifier is most commonly used when there are two or more 
 * files sharing the same global variables or functions.
 */

#include <stdio.h>
 
int count ;
extern void write_extern();
 
int main() {

   count = 5;
   write_extern();
   
   return 0;
}
