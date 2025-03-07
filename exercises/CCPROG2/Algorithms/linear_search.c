#include <stdio.h>

int LinearSearch(int key, int A[], int n) {
    int i = 0;
    while (i < n) {
        if (key == A[i])
            return i;
        i++;
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

    int idx = LinearSearch(key, A, size);
    if (idx > -1) 
        printf("\n%d is found at index %d\n", key, idx);
    else
        printf("Element not found\n");
    
}