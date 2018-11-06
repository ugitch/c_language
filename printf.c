#include <stdio.h>

int main(void) {
    char letter = 'G';
    int negNumber = -1;
    unsigned int age = 40;
    char num = 289;

    printf("%d\n", num);

    printf("My name begins with %c\n", letter);
    printf("Look, I'm negative! --> %d\n", negNumber);
    printf("I am %d years old!\n", age);
    printf("\t in octal(base 8) = %o\n", age);
    printf("\t in hex(base 16) = %x\n", age);

    printf("G's numeric value is %d\n", letter);
    printf("-1 as hex is %x\n", negNumber);
    printf("-1 as an unsigned int is %u\n", negNumber);
    printf("40 as a letter is %c\n", age );
}