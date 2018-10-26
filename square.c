#include <stdio.h>
double square(double);

int main() {
    double a = 2.5;
    double aSquared = square(a);
    printf("%.2lf squared = %.2lf\n", a, aSquared);
    return 0;
}

double square(double a) {
    return a*a;
}
