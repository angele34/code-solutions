#include <stdio.h>

void PrintList(char S[], int n) {
    int j;
    printf("Original array: \n");
    for(j = 0; j < n; j++) {
        printf("%c", S[j]);
    }
    printf("\n");
}
// Problem 1.7
int CountUpper(char S[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] >= 'A' && S[i] <= 'Z') 
            count++;
    }
    return count;
}
// Problem 1.8
void ConvertUpper(char S[], int n) {
    printf("\nLetters converted to uppercase: \n");
    for (int i = 0; i < n; i++) {
        if (S[i] >= 'a' && S[i] <= 'z') 
            printf("%c", S[i]-32);
        else   
            printf("%c", S[i]);
    }
    printf("\n");
}

int main() {
    char S[7] = {'C', 'o', 'M', 'p', 'r', 'o', '2'};
    int count = CountUpper(S,7);
    PrintList(S,7);
    printf("\nThere are %d upper case letters\n", count);
    ConvertUpper(S,7);
    return 0;
}