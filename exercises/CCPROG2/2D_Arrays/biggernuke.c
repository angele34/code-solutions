/*
Problem #12: Bigger Nuke
Write a function biggerNuke that accepts a 2-D integer array of positive integers, 
the number of rows and the number of columns in the array, as well as a two integers 
targetRow and targetColumn. The function should nuke the cell on the target row and column, 
as well as the four adjacent cells around it, by setting those cells to -1. 
Make sure you are not accessing indices that are out of bounds. 
The function does not return anything. Assume the maximum number of columns of the array is 100.
*/

#include <stdio.h>

void biggerNuke(int arr[100][100], int row, int col, int targetRow, int targetCol) {
    printf("Enter a %d by %d 2D Array: \n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    // Nuke the target cell
    arr[targetRow][targetCol] = -1;
    // Nuke the cell above the target
    if (targetRow > 0) {
        arr[targetRow-1][targetCol] = -1;
    }
    // Nuke the cell below the target
    if (targetRow < row-1) {
        arr[targetRow+1][targetCol] = -1;
    }
    // Nuke the cell to the left of the target
    if (targetCol > 0) {
        arr[targetRow][targetCol-1] = -1;
    }
    // Nuke the cell to the right of the target
    if (targetCol < col-1) {
        arr[targetRow][targetCol+1] = -1;
    }
    printf("Nuked Array: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == -1) {
                printf("\033[1;31m%3d\033[0m ", arr[i][j]);
            } else printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[100][100];
    int row, col, targetRow, targetCol;

    do {
        printf("Input the number of rows not greater than 100: \n");
        scanf("%d", &row);
        printf("Input the number of columns not greater than 100: \n");
        scanf("%d", &col);
    } while (row > 100 || col > 100);

    do {
        printf("Enter a valid target row and target column to nuke: \n");
        scanf("%d %d", &targetRow, &targetCol);
    } while (targetRow >= row || targetCol >= col);

    biggerNuke(arr, row, col, targetRow, targetCol);
    
    return 0;
}