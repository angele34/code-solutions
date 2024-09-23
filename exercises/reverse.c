#include <stdio.h>

int main() {
    int n;
    do {
        printf("Enter a three digit integer\n");
        scanf("%d", &n);
    } while (n < 100 || n > 999);

    while (n > 0) {
        int last = n % 10;
        n/= 10;
        printf("%i\n", last);
    }
}