/*
Problem #13: Multiplication Table
Write a program that asks the user to input an integer n. n can be any value from 2 to 10, inclusive. 
If the user inputs an invalid integer, the program should continuously ask until a valid input is given.
Afterwards, generate a multiplication table inside a two-dimensional array.
For example, if n = 5, the array should contain the following 
(this only shows the values up to fifth row and column):

1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
5 10 15 20 25

Thereafter, use a nested loop to display the multiplication table to the user. Make sure the numbers align to
make it look good.

*/

#include <stdio.h>

void Multiplication_Table(int n) {
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = (i+1) * (j+1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    do {
        printf("Input a value from 2 to 10: \n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);
    Multiplication_Table(n);
    return 0;
}