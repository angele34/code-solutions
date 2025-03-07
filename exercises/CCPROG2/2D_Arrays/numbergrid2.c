/*
Problem #3: Number Grid 2
Declare a 3 × 4 integer array. Use a nested loop (don’t use array initialization) to assign each cell with values
as follows:
1 1 1 1
2 2 2 2
3 3 3 3
Use another nested loop to display all the elements arranged in a grid.
*/

#include <stdio.h>

int main() {
    int number_grid[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            number_grid[i][j] = i+1;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", number_grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}