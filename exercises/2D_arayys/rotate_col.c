/*
Problem #18: Rotate Column
Write a function that accepts a 4 × 4 integer array. 
The function moves the first (leftmost) column to the last
(rightmost) column, and shifts the rest of the columns accordingly. 
*/

#include <stdio.h>
#define SIZE 4

void rotateCol(int arr[][SIZE]) {
    int i,j;
    printf("Input a 4x4 integer array: \n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int B[SIZE][SIZE];
    for (i = 0; i < SIZE; i++) {
        int temp = arr[i][0];
        printf("%d\n", temp);
        for (j = 1; j < SIZE; j++) {
            B[i][j-1] = arr[i][j];
        }
        B[i][SIZE-1] = temp;
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
    rotateCol(a);
}