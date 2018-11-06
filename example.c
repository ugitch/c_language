#include <stdio.h>

int main(void) {
    // //! showMemory(start=65800)
    
    int y = 2147483647;
    printf("y = %x (hex)", y);
    
    double d = 4.669;
    printf("My number is %.2f.",d);

    int x = 5;
    double d1 = 11/x;
    double d2 = 11/(double)x;
    printf("d1 - d2 = %.2f\n", d1-d2);

}