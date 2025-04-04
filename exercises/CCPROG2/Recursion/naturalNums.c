#include <stdio.h>

void displayNaturalNums(int n) {
    if (n <= 50) {
        printf("%d   ", n);
        displayNaturalNums(n+1);
    }
}

int main() {
    displayNaturalNums(1);
    return 0;
}