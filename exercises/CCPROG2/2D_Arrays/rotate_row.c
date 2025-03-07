/*
Problem #17: Rotate Row
Write a function that accepts a 4 × 4 integer array. The function moves the last (bottom) row 
to the first (top) row, and shifts the rest of the rows accordingly.
*/

#include <stdio.h>
#define SIZE 4

void rotateRow(int arr[][SIZE]) {
    int i,j;
    printf("Input a 4x4 integer array: \n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int B[SIZE][SIZE];
    
    for (j = 0; j < SIZE; j++) {
        B[0][j] = arr[SIZE-1][j];
    }

    for (i = 1; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            B[i][j] = arr[i-1][j];
        }
    }
    
    printf("\nRotated Array:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[SIZE][SIZE];
    rotateRow(a);
}