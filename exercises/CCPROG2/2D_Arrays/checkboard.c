/*
Problem #14: Checkboard
Without using array initialization or brute force, create an 8 × 8 character array with the following contents:
W B W B W B W B
B W B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B
B W B W B W B W
W B W B W B W B
B W B W B W B W
Thereafter, display the contents of the array arranged in a grid.
*/

#include <stdio.h>

int main() {
    char checkboard[8][8];
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) 
                checkboard[i][j] = 'W';
            else 
                checkboard[i][j] = 'B';
            printf("%2c ", checkboard[i][j]);
        }
        printf("\n");
    }
    return 0;
}