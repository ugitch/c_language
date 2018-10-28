#include <stdio.h>

#define SIZE 9

int sudoku[9][9] = {};
int tries = 0;
char filename[] = "sudoku_solution.txt";

// prototypes
void enter_sudoku();
int solve_sudoku();
int unallocated_cells(int *, int *);
int is_regular_play(int n, int r, int c);
void print_sudoku();
void log_sudoku_solution(FILE *ofile);


int main() {

    printf("New log for sudoku solution!\n\n");
    FILE *ofile = fopen(filename, "w");
    fclose(ofile);
    
    enter_sudoku();

    if (solve_sudoku())
        print_sudoku();
    else
        printf("No solution\n");

    return 0;
}

void enter_sudoku() {
    int i, j;
    printf("Enter sudoku 9x9 to solve, separate number by spaces (or enter new line), enter 0 for empty spaces in sudoku:\n");

    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
            scanf("%d", &sudoku[i][j]);
}


int solve_sudoku() {
    int row, column;
    tries++;

    // logging path to solution
    FILE *ofile = fopen(filename, "a");
    log_sudoku_solution(ofile);
    fclose(ofile);

    if(unallocated_cells(&row, &column) == 0)
        return 1;

    int n;
    // number (1-9) to put in sudoku
    for (n=1; n<=SIZE; n++) {
        if (is_regular_play(n, row, column)) {
            sudoku[row][column] = n;
            if (solve_sudoku())
                return 1;
            sudoku[row][column] = 0;
        }
    }
    return 0;
}

int unallocated_cells(int *row, int *column) {
    int unallocated = 0;
    int i, j;

    // find vacancy in sudoku
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            if (sudoku[i][j] == 0) {
                *row = i;
                *column = j;
                unallocated = 1;
                return unallocated;
            }
        }
    }
    return unallocated;
}

int is_regular_play(int n, int r, int c) {
    int i,j;
    //checking in row
    for(i=0;i<SIZE;i++) {
        //there is a cell with same value
        if(sudoku[r][i] == n)
            return 0;
    }
    //checking column
    for(i=0;i<SIZE;i++) {
        //there is a cell with the value equal to i
        if(sudoku[i][c] == n)
            return 0;
    }
    //checking sub sudoku
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++) {
        for(j=col_start;j<col_start+3;j++) {
            if(sudoku[i][j]==n)
                return 0;
        }
    }
    return 1;
}

void print_sudoku() {   
    int i,j;

    printf("Solved sudoku in %d tries:\n", tries);
    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
}

void log_sudoku_solution(FILE *ofile) {
    int i, j;

    fprintf(ofile, "Current state of sudoku, try %d:\n", tries);
    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            fprintf(ofile, "%d ", sudoku[i][j]);
        }
        fprintf(ofile, "\n");
    }
}
