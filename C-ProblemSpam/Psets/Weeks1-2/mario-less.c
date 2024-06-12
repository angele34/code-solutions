#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void) {
    int height;
    do {
        height = get_int("Height: ");
    } while (height < 1);

    for (int i = 0; i < height; i++) {
        for (int j = height-1-i; j > 0; j--) {
            printf(" ");
        }
        for (int j = 0; j < i+1; j++) {
            printf("#");
        }
        printf("\n");
    }
}
