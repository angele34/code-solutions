#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void) {
    int cash;
    do {
        cash = get_int("Change owed: ");
    } while (cash < 0);

    int coins = 0;
    // quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
    while (cash > 0)
    if (cash-25 >= 0) {
        cash -= 25;
        coins++;
    }
    else if (cash-10 >= 0) {
        cash-=10;
        coins++;
    }
    else if (cash-5 >= 0) {
        cash-=5;
        coins++;
    }
    else if (cash-1 >= 0) {
        cash-=1;
        coins++;
    }
    printf("%d\n", coins);
}


