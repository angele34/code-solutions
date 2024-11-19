#include <stdio.h>

int main() {
    int height;
    do {
        printf("Enter height of triangle: ");
        scanf("%d", &height);
    } while(height < 0);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}