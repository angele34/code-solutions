#include <stdio.h>
#define MULTIPLIER 10

void PrintLine() {
    printf("+");
    for (int i = 1; i < MULTIPLIER*5; i++) {
        for (; i % 5 != 0; i++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

int main() {
    printf("\n%12s%s", " ", "Multiplication table from 1-10\n");
    PrintLine();
    for (int i = 1; i <= MULTIPLIER; i++) {
        for (int j = 1; j <= MULTIPLIER; j++) {
            printf("|%4d", i*j);
            
        }
        printf("|\n");
        PrintLine();
    }
    return 0;
}