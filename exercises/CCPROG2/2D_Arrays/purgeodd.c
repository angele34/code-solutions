/*
Problem #10: Purge Odd 2D
Write a function purgeOdd that accepts an 2-D integer array, the number of rows and the number of columns
in the array. The function should change all the odd integers in the array to 0. 
The function does not return anything. Assume the maximum number of columns of the array is 100.
*/

#include <stdio.h>

void purgeOdd(int arr[100][100], int row, int col) {
    printf("Enter a 2D Array: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nNew array without odd elements: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] % 2 == 1) {
                arr[i][j] = 0;
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[100][100];
    int row, col;
    do {
        printf("Input the number of rows not greater than 100: \n");
        scanf("%d", &row);
        printf("Input the number of columns not greater than 100: \n");
        scanf("%d", &col);
    } while (row > 100 || col > 100);
    purgeOdd(arr, row, col);
    return 0;
}