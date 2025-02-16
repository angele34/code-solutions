/*
Problem #4: Number Grid 3
Declare a 4 × 4 integer array. Use a nested loop (don’t use array initialization)
to assign each cell with values as follows:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Use another nested loop to display all the elements arranged in a grid.
*/

#include <stdio.h>

int main() {
    int number_grid[4][4] = {0};
    int num = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            number_grid[i][j] = num;
            num++;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", number_grid[i][j]);
        }
        printf("\n");
    }
}