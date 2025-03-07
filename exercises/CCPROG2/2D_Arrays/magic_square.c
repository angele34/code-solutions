/*
Problem #19: Magic Square

A magic square is a 2-D array where the sum of each rows, columns, and diagonals are all the same. 
Write a function isMagicSquare that accepts a 2-D integer array, and the dimension of the array 
(assume the array is always square). The function should return 1 if it is a magic square, or 0 otherwise.
*/

#include <stdio.h>
#define MAX_SIZE 100

int magicSquare(int square[][MAX_SIZE], int n, int m) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &square[i][j]);
        }
    }
    int initialSum = 0;
    for (int j = 0; j < m; j++) {
        initialSum += square[0][j];
    }
     // Check if the sum of each col is equivalent
    for (i = 1; i < n; i++) {
        int sumCol = 0;
        for (j = 0; j < m; j++) {
            sumCol += square[i][j];
        }
        if (sumCol != initialSum)
            return 0; // not a magic square
    }

    // Check if the sum of each row is equivalent
    for (i = 0; i < n; i++) {
        int sumRow = 0;
        for (j = 0; j < m; j++) {
            sumRow += square[j][i];
        }
        if (sumRow != initialSum)
            return 0; // not a magic square
    }

    // Check if the top-left to bottom right diagonals are equivalent
    int sumLDiagonal = 0;
    for (i = 0; i < n && i < m; i++) {
        sumLDiagonal += square[i][i]; // square[i][i] = square [1][1]
    }
    if (sumLDiagonal != initialSum)
        return 0; // not a magic square

    // Check if the top-right to bottom left diagonals are equivalent
    int sumRDiagonal = 0;
    for (i = 0; i < n && i < m; i++) {
        sumRDiagonal += square[i][m-1-i];
    }
    if (sumRDiagonal != initialSum)
        return 0; // not a magic square

    return 1;
}

int main() {
    int n,m;
    printf("Enter the size of the 2D array n and m: \n");
    scanf("%d %d", &n, &m);
    printf("Enter a %d by %d 2D array: \n\n", n, m);
    int square[MAX_SIZE][MAX_SIZE];
    int result = magicSquare(square, n, m);
    if (result == 1)
        printf("\nMagic Square!\n");
    else   
    printf("\nNot a Magic Square\n");
    return 0;
}