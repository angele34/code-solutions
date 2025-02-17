/*
Problem #6: Last Column
Declare a 3 × 3 2-D integer array. Ask the number to continuously input 9 numbers. 
Store the numbers in the array in row-major order. 
Thereafter, output the sum of the last (rightmost) column of the array
*/

#include <stdio.h>

void Print_Sum(int n[3][3]) {
    int sum = 0;
    printf("Array in Row-major order\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", n[i][j]);
            if (j == 2) {
                sum += n[i][j];
            }
        }
        printf("\n");
    }
    printf("\nSum of the last rightmost column elements: %d \n", sum);
}

int main() {
    int n[3][3];
    int i = 0;
    printf("Enter 9 numbers\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &n[i][j]);
        }
    }
    printf("\n");
    Print_Sum(n);
    return 0;
}