#include <stdio.h>

int main(void) {
    int N = 6;
    int x = -(N*N);
    int i;
    for (i=1; i<3*N+1; i++) {
        printf("%d ", x);
        x += 2*i - 1;           
    }
}