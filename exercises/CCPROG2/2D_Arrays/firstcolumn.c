/*
Problem #7: First Column

Declare a 3 × 3 2-D integer array. Ask the number to continuously input 9 numbers. \
Store the numbers in the array in column-major order.
Thereafter, output the sum of the first (top-most) row of the array.
*/

#include <stdio.h>

void Print_Sum(int n[3][3]) {
    int sum = 0;
    printf("Array in Column-major order\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", n[i][j]);
            if (i == 0) {
                sum += n[i][j];
            }
        }
        printf("\n");
    }
    printf("\nSum of the first top-most row of the array %d \n", sum);
}

int main() {
    int n[3][3];
    int i = 0;
    printf("Enter 9 numbers\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &n[j][i]);
        }
    }
    printf("\n");
    Print_Sum(n);
    return 0;
}