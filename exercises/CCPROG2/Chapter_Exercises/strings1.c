#include <stdio.h>
#include <string.h>

void printStr(char str[][10], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", str[i]);
    }
}

void extractChar(char str[], int n) {
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i] - 32);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            printf("%c",str[i]);
        }
    }
}

void sortStr(char str[][10], int n) {
    // Ascending
    char temp[10];
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(str[j], str[j+1] ) > 0) {
                strcpy(temp,str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
    }
}

int countStrFreq(char str3[][10], int n, char s[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(str3[i],s) == 0)
            count++;
    }
    return count;
}

void removeStr(char arr1[][10], int *size1, char arr2[][10], int size2) {
    int size = 0;
    for (int i = 0; i < *size1; i++) {
        int found = 0;
        for (int j = 0; j < size2; j++) {
            if (strcmp(arr2[j], arr1[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(arr1[size], arr1[i]);
            size++;
        }
    }
    *size1 = size;
}

int main() {
    char str[] = "The hills are alive, then so am I!";
    int n = strlen(str);
    // printf("%d", n);
    extractChar(str,n);
    printf("\n");

    char str2[][10] = {"THE", "AM", "WILL"};
    int len = sizeof(str2) / sizeof(str2[0]);
    sortStr(str2,len);
    printStr(str2,len);

    char str3[][10] = {"THE", "AM", "WILL", "AM"}; 
    int len2 = sizeof(str3) / sizeof(str3[0]);
    int count = countStrFreq(str3, len2, "AM");
    printf("\ncount: %d\n", count);

    char arr1[][10] = {"APPLE", "BANANA", "ORANGE", "GRAPE", "PEACH"};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    char arr2[][10] = {"BANANA", "GRAPE"};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    removeStr(arr1, &size1, arr2, size2);
    printStr(arr1,size1);

    return 0;
}