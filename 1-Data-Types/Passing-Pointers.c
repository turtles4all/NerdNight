#include <stdio.h>
#include <stdlib.h>

//global
int ISR_flag;

// Set ISR flag on interrupt
void ISR(int sig){
	ISR_flag = 1;
	fprintf(stderr, "ISR captured signal: %d\n", sig);
}

void function(int *flag){
	printf("From called Function: ISR_flag = %d, Address is %p\n", *flag, flag);
}

int main( int argc, char *argv[] ) {
	printf("From Main: ISR_flag = %d, Address is %p\n", ISR_flag, &ISR_flag);
	function(&ISR_flag);
	
}
