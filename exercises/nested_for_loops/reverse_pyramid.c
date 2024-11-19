#include <stdio.h>

int main() {
    int height;
    do {
        printf("Enter height of triangle: ");
        scanf("%d", &height);
    } while(height < 0);

    for (int i = height; i > 0; i--) {
        for (int j = 1; j < i+1; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}