/*
 * variable-sizes.c
 */
 
#include <stdio.h>

struct mystruct {
		int myint;
		char mychar;
		double long mybutnumber;
	};

int main(void){

    int integerType;
    float floatType;
    double doubleType;
    char charType;
	struct mystruct myStructType;
	
    // Sizeof operator is used to evaluate the size of a variable
    printf("Size of int: %ld bytes\n",sizeof(integerType));
    printf("Size of float: %ld bytes\n",sizeof(floatType));
    printf("Size of double: %ld bytes\n",sizeof(doubleType));
    printf("Size of char: %ld byte\n",sizeof(charType));
    printf("Size of myStructType: %ld bytes\n",sizeof(myStructType));

    return 0;
}
