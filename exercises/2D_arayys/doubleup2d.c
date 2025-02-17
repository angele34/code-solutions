/*
Problem 9: Double Up 2D

Write a function doubleUp2d that accepts a 2-D double array, the number of rows and the number of columns
of the array. The function should then multiply each value in the array by 2. 
The function does not return anything. Assume the maximum number of columns of the array is 100.
*/

#include <stdio.h>

void doubleUp2d(double arr[100][100], int row, int col) {
    printf("Enter a 2D Array: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] *= 2;
            printf("%4.2lf ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double arr[100][100];
    int row, col;
    do {
        printf("Input the number of rows not greater than 100: \n");
        scanf("%d", &row);
        printf("Input the number of columns not greater than 100: \n");
        scanf("%d", &col);
    } while (row > 100 || col > 100);
    doubleUp2d(arr, row, col);
    return 0;
}