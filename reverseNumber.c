 #include <stdio.h>
 
 int main () {
    int number = 251;
    int rem, rev = 0;
    
    while (number >= 1) {
        rem = number % 10;
        rev = rev * 10 + rem;
        number = number / 10;
    }
    printf ("%d \n", rev);
 }