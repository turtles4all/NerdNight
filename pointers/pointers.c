/*
 * pointers.c
 * 
 */
#include <stdio.h>

int main () {

	int  var1 = 20;
	char var2[10] = "HELLO";
	//print the address of variables
	printf("Address of var1 variable: %p\n", &var1  );
	printf("Address of var2 variable: %p\n", &var2  );
	
	int *pvar1 = &var1;
	char *pvar2 = var2;
	printf("Address of pvar1 variable: %p\n", pvar1  );
	printf("Address of pvar2 variable: %p\n", pvar2  );
	
	//pointer dereference
	printf("value of pvar1 variable: %d\n", *pvar1  );
	printf("value of var2[0] variable: %c\n", *pvar2  );
	
   return 0;
}
