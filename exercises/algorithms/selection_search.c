#include <stdio.h>
#define SIZE 6

void PrintList(int L[], int S) {
    int j;
    for(j = 0; j < S; j++) {
        printf("%d ", L[j]);
    }
    printf("\n");
}

void SelectionSort(int A[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (A[min] > A[j])
                min = j;
        if (i!=min) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
        printf("%d ", A[i]);
    }
    printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[6] = {2, 9, 8, 1, 7, 6};
    printf("Numbers before sort: \n");
    PrintList(A,6);
    printf("Sorted array: \n");
    SelectionSort(A,6);
}