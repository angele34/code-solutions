/*
Problem #2: Number Grid
Declare a 4 × 3 integer array. Use a nested loop (don’t use array initialization) 
to assign each cell with values as follows:
1 2 3
1 2 3
1 2 3
1 2 3
Use another nested loop to display all the elements arranged in a grid.
*/

#include <stdio.h>

int main() {
    int number_grid[4][3];

    // Assign values 1 2 3 to the array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            number_grid[i][j] = j+1;
        }
    }
    // Display the number grid
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", number_grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}