#include <stdio.h>
#define CARD_SIZE 3

void printLine() {
    printf("+");
    for (int i = 1; i <= CARD_SIZE*4; i++) {
        for (; i % 4 !=0; i++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

int main() {
    int i = 0;
    printLine();
    for (i=1;i<= CARD_SIZE*4; i++) {
        // not divisible by 3
        for (; i%CARD_SIZE != 0; i++) {
            switch(i) {
                case 10:
                    printf("|%3s", " ");
                    break;
                case 11:
                    printf("|%2d", 0);
                    break;
                default:
                    printf("|%2d ", i);
                    break;
                }  
            }
            switch(i) {
                case 12:
                    printf(" |%4s\n", "|");
                    break;
                default:
                    printf("|%2d |\n", i);
                    break;
            }
            printLine();
    }
}