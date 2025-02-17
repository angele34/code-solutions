/*
Problem #8: Count 2D
Write a function count2d that accepts a 2-D character array, 
the number of rows and the number of columns of the array, 
and a character parameter key which is the character to count. 
The function should return how many times that character appeared in the 2-D array. 
Assume the maximum number of columns of the array is 100.
*/

#include <stdio.h>

int count2d(char arr[100][100], int row, int col, char key) {
    printf("Enter a 2D Array: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (key == arr[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char arr[100][100];
    int row, col;
    char key;
    do {
        printf("Input the number of rows not greater than 100: \n");
        scanf("%d", &row);
        printf("Input the number of columns not greater than 100: \n");
        scanf("%d", &col);
        printf("Enter a key: \n");
        scanf(" %c", &key);
    } while (row > 100 || col > 100);
    int count = count2d(arr, row, col, key);
    printf("The key '%c' appeared %d times in the 2D array", key, count);
    return 0;
}