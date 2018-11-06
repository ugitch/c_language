#include <stdio.h>

int main(void) {
    int acc = 0;
    int adder = 1;
    int N = 6;
    int i;
    for (i=0; i<3*N; i++) {
        if (i == 0) {
            acc = -(N*N);
            printf("%d ", acc);
        }
        else {
            acc += adder;
            printf("%d ", acc);
            adder += 2;
        }
    }
}