#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	int *array = malloc(1 * sizeof(char *));
	
	for(int i = 0; i < 2; i++){
		if(i > 0){
			int *tmp = realloc(array, sizeof(array) + sizeof(char *));
			memset(tmp, 0, sizeof(char *));
			array = tmp;
		}
	}
	free(array);
	return 0;
}

