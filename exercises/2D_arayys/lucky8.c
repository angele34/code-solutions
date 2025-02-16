/*
Problem #1: Lucky 8
Declare a 3 × 3 integer array. Use a nested loop (don’t use array initialization) 
to assign the value 8 to all the cells. 
Use another nested loop to display the contents of the array arranged in a grid.
*/

 #include <stdio.h>

int main() {
    int lucky_8[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            lucky_8[i][j] = 8;
        }   
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", lucky_8[i][j]);
        }
        printf("\n");
    }
}

