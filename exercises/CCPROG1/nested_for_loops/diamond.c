#include <stdio.h>

int main() {
    int diamond;
    do {
        printf("Enter height of diamond greater than 2: ");
        scanf("%d", &diamond);
    } while(diamond < 2);

    // Print upper half of diamond
    for (int i = 1; i <= diamond; i++) {
        for (int j = 0; j < diamond + 2 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    // Print lower half of diamond
    for (int i = diamond; i > 0; i--) {
        for (int j = 0; j < diamond + 2-i; j++) {
            printf(" ");
        }
        for (int j = 0; j <2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
}