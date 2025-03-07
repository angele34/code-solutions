#include <stdio.h>

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void sortArray(int arr[], int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int countFreq(int arr[], int len, int key) {
    int freq = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == key) {
            freq++;
        }
    }
    return freq;
}

void shiftArray(int arr[], int len) {
    int element = arr[len-1];
    for (int i = len-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = element;
}

int main() {
    int arr[] = {1,3,-4,2,3}; // -4,1,2,3,3
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("length of array: %d\n", len);
    sortArray(arr,len);
    printArray(arr,len);
    int freq = countFreq(arr,len,3);
    printf("\n%d\n", freq);

    shiftArray(arr,len);
    printArray(arr,len);
    

    return 0;
}