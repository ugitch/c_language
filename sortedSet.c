#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //! showArray(list, cursors=[i,j])
    // Sorting from smallest to largest
    double list[] = {-0.32, 0.06, 0.98, 0.53, 1.53, 1.98, 2.34}; /* unsorted list */
    int n = 7;
    // int i, j, index, min;
    // int swap;

    // my way
    // for (i=0; i<n-1; i++) {
    //     index = i;
    //     min = list[i];
    //     for (j=i+1; j<n; j++) {
    //         if (list[j] < min) {
    //             min = list[j];
    //             index = j;
    //         }
    //     }
    //     if (index != i) {
    //         swap = list[i];
    //         list[i] = min;
    //         list[index] = swap;
    //     }
    // }

    /* double temp = 0; */

    // better way
    /* for (int i = 0; i < n - 1; i++) { */
    /*     for (int j = 0; j < n - i - 1; j++) { */
    /*         if (list[j] > list[j+1]) { */
    /*             temp = list[j]; */
    /*             list[j] = list[j+1]; */
    /*             list[j+1] = temp; */
    /*         } */
    /*     } */
    /* } */

    // another way
    double temp = 0;

    for (int i = 1; i < n; i++) {
      int j = i;
      while (list[j-1] > list[j] && j > 0) {
	temp = list[j-1];
	list[j-1] = list[j];
	list[j] = temp;
	j--;
      }
    }
    
    printf("\nSorted list: \n");
    for (int i=0; i<n; i++)
        printf("%.2lf ", list[i]);
    printf("\n");

    return EXIT_SUCCESS;
}
