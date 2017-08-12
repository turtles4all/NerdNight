#include <stdio.h>

int main(){
        int x, y, t;

        for (x = 1; x <= 14; x++) {
                y = 14 - x;
                printf("%d|%d\n", x, y);
                if ((x*x) + (y*y) == 100)
                printf("match\n");
        }
        return 0;
}
