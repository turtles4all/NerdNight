/*
 * XORswap.c
 */

#include <stdio.h>

void xorSwap (int *x, int *y);
void xorSwap2(int *x, int *y);

int main(int argc, char **argv){
	
	int x = 10;
	int y = 50;
	printf("Values of X and Y before swap\n");
	printf("X = %d\n", x);
	printf("Y = %d\n", y);
	
	xorSwap(&x, &y);
	printf("Values of X and Y after swap\n");
	printf("X = %d\n", x);
	printf("Y = %d\n", y);
	
	xorSwap2(&x, &y);
	printf("Values of X and Y after swap 2\n");
	printf("X = %d\n", x);
	printf("Y = %d\n", y);
	
	return 0;
}

void xorSwap(int *x, int *y){
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
 }

void xorSwap2(int *x, int *y){
     *x^=*y^(*y=*x);
 }
