#include <stdio.h>
#define SIZE 5
// Problem 1.1

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
    
// time complexity O(n)
int isIncreasingOrder(int A[], int n) {
    int y = 1;
    for (int i = 0; i < n-2 && y != 0; i++) {
        if(A[i] < A[i+1]) {
            y = 1;
        } else {
            y = 0;
        }
    }
    return y;
}

int LinearSearch(int key, int A[], int n) {
    int found = 0, i = 0;
    while (i<n && !found) {
        if (key == A[i])
            found=1; // break out of the loop in the next iteration
        else  
            i++; // increment index
    }
    if(found) 
        return i; // return the index of the element where key is found
    else 
        return -1; // key not found
}

int main() {
    int A[SIZE];
    // Take input list (8 elements)
    printf("Enter 5 numbers separated by spaces: ");
    InputList(A, SIZE);
    // Print array elements given by user
    printf("\nNumbers entered: \n\n");
    PrintList(A, SIZE);

    int yes = isIncreasingOrder(A, SIZE);
    if (yes > 0) printf("\nIncreasing order\n");
    else printf("\nNot in increasing order\n");

    // increasing
    // 1 2 3 4 5 
    // not increasing
    // 1 2 4 3 5
    // not increasing
    // 5 7 6 1 0
    // increasing
    // 10 20 30 40 50

    // 50 40 30 20 10
}