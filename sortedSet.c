#include <stdio.h>

int main(void) {
    //! showArray(list, cursors=[i])
    // Sorting from smallest to largest
    int list[] = {759, 14, 2, 900, 106, 77, -10, 8, -3, 5}; /* unsorted list */
    int n = 10;
    int i, j, index, min;
    int swap;
    
    for (i=0; i<=n-2; i++) {
        index = i;
        min = list[i];
        for (j=i+1; j<=n-1; j++) {
            if (list[j] < min) {
                min = list[j];
                index = j;
            }
        }
        if (index != i) {
            swap = list[i];
            list[i] = min;
            list[index] = swap;
        }
    }
    
    printf("\nSorted list: \n");
    for (i=0; i<n; i++)
        printf("%d ", list[i]);

    return 0;
}
