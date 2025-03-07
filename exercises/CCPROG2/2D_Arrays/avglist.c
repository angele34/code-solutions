/*
Problem #15: Average List
Write a function that accepts an n × m 2-D float array A, a 1-D float array B of size n, 
and the integers n and m. The program should compute the average value of each row 
in A and write the results in the corresponding index in B. The function does not return anything.
Assume that the n and m are positive integers not greater than 20.
*/

#include <stdio.h>

void computeAverage(float A[][20], float B[20], int n, int m) {
    // Take input values
    do {
        printf("Input a value of n not greater than 20: \n");
        scanf("%d", &n);
        printf("Input a value of m not greater than 20: \n");
        scanf("%d", &m);
    } while (n > 20 || m > 20);
    
    printf("Input a %d by %d 2D array: \n", n, m);
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%f", &A[i][j]); // *(A + i * m + j) pointer notation
        }
    }

    // Compute for the average in each row
    for (i = 0; i < n; i++) {
        float sum = 0;
        for (j = 0; j < m; j++) {
            sum += A[i][j];
        }
        B[i] = sum / m;
    }
    // Print the average list
    for (i = 0; i < n; i++) {
        printf("Average value of row %d: %.2f \n", i, B[i]);
    }
    printf("\n");
}

int main() {
    int n,m;
    float A[20][20], B[20];
    computeAverage(A, B, n, m);
    return 0;
}

