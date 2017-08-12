/*
 * strings
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	//char greeting1[7] = {'H', 'e', 'l', '\0', 'o', 'o','\0'};
	
	char greeting1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char greeting2[] = "Hello 2";
	char *greeting3 = "Hello 3";
	
	printf("Greeting message1: %s\n", greeting1 );
	printf("Greeting message2: %s\n", greeting2 );
	printf("Greeting message3: %s\n", greeting3 );
	
	//printf("Greeting message3: %s\n", greeting1+4 );
	
	//Strings are hard....
	
	char *pointer = greeting1;
	for (int i = 0; i < sizeof(greeting1) ; i++){	
		printf("greeting[%d] = %c \n", i, *pointer);
		pointer++;
	}
	
	return 0;
}

