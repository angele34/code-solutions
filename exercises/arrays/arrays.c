#include <stdio.h>
#define SIZE 8

void InputList(int A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

void PrintList(int L[], int S) {
    int j;
    for(j = 0; j < S; j++) {
        printf("%d\n", L[j]);
    }
}

int countOdd(int A[], int n) {
    int i;
    int odd = 0;
    for (i = 0; i < n; i++) {
        if (A[i] % 2 == 1)
            odd++;
    }
    return odd;
}

int getMaxiumum(int A[], int n) {
    int i;
    int mx = 0;
    for (i = 1; i < n; i++) {
        if (A[mx] < A[i])
            mx = i;
    }
    return A[mx];

}

float getAverage(int A[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum += A[i];
    }
    return (float)sum / n;
}

/*
function that displays the elements that are higher than the passed value. 
for ex. displayHigher(A, 20, 50) should display all the elements 
in A with a size of 20  that are higher than given range
*/

void displayHigher(int A[], int n, int range) {
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        if (A[i] > range) {
            printf("%d ", A[i]);
        }
    } printf("]");
    printf("\n");
}

/*
function that displays the elements between the lower bound and upper bound, inclusive. 
For ex. displayRangeInc(A, 20, -10, 50) should display all the elements in A 
with a size of 20 between -10 and 50, including the -10 and 50. 
*/

void displayRangeInc(int A[], int n, int lower, int upper) {
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        if (A[i] >= lower && A[i] <= upper) {
            printf("%d ", A[i]);
        }
    } printf("]");
    printf("\n");
}

int main() {
    /*
    Sample inputs:

    1 2 3 4 5 6 7 8

    1 3 5 7 9 11 13 16
    
    1 1 1 1 1 1 1 1
    */

    int A[SIZE];
    // Take input list (8 elements)
    printf("Enter 8 numbers separated by spaces: ");
    InputList(A, SIZE);
    // Print array elements given by user
    printf("\nNumbers entered: \n\n");
    PrintList(A, SIZE);
    // Returns # of odd elements
    int oddNum = countOdd(A, SIZE);
    printf("\nNumber of odd elements in the array: %d\n", oddNum);
    // Returns the largest number in the array
    int mxNum = getMaxiumum(A,SIZE);
    printf("\nLargest number in the array: %d\n", mxNum);
    // Get the average of the numbers in the array
    float avgNum = getAverage(A, SIZE);
    printf("\nAverage of numbers in the array: %.3f\n", avgNum);
    // Display all the elements with the given size higher than the given range
    printf("\nNumbers greater than 6: ");
    displayHigher(A, SIZE, 6);
    printf("\nNumbers within the range of 2 and 5: \n");
    displayRangeInc(A, SIZE, 2, 5);
    return 0;
}
