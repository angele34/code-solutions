/*
Binary Search algorithm 

- Knuth 1998, §6.2.1 ("Searching an ordered table"), subsection "Algorithm B".

Works on sorted arrays and begins by comparing an element in the middle of the array with the target value.
If the target value matches the element, its position in the array is returned.
If the target value is less than the element, the search continues in the lower half of the array.
If the target value is greater than the element, the search continues in the upper half of the array.
By doing this, the algorithm eliminates the half in which the target value cannot lie in each iteration.

Time Complexity: 
Best Case: O(1)
Worst Case: O(log n)
*/

#include <stdio.h>

void sortArray(int A[], int n) {
    // Using bubble sort algorithm
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }
    }
}

int binarySearch(int A[], int n, int key) {
    int left = 0;
    int right = n-1;

    while (left <= right) {
        int mid = left + (right-left) / 2;
        if (A[mid] == key) 
            return mid;
        else if (A[mid] < key)
            left = mid + 1; // Search right half
        else 
            right = mid - 1; // Search left half
    }
    return -1;
}

int main() {
    int size, key;
    printf("Enter size of the array: \n");
    scanf("%d", &size);

    int A[size];
    printf("Enter %d elements separated by spaces: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }
    printf("Enter the element to find: \n");
    scanf("%d", &key);

    sortArray(A, size);
    int idx = binarySearch(A, size, key);
    if (idx > -1) 
        printf("\n%d is found at index %d\n", key, idx);
    else
        printf("Element not found\n");
}