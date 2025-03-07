/*
Problem #5: Number Grid 4
Declare a 4 × 4 integer array. Use a nested loop (don’t use array initialization) to assign each cell with values
as follows:
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13
Use another nested loop to display all the elements arranged in a grid.
*/

#include <stdio.h>

int main() {
    int arr[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {  
            arr[i][j] = (4-i) * (j+1);  
            if (i > 0) {
                arr[i][j] = arr[i-1][j]-1; 
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) { 
            printf("%-2d  ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
