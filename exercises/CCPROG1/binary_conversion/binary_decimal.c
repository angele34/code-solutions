#include <stdio.h>

int main() {
    long bin;
    printf("Enter a binary number: ");
    scanf("%ld", &bin);
    long tmp = bin;
    
    // Get length of binary
    int len = 0;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    // Convert binary to decimal
    int dec = 0, num = 1;
    for (int i = 0; i < len; i++) {
        if (bin % 10 != 0) {
            dec += num;
        }
        num*=2;
        bin /= 10;
    }
    printf("Binary to Decimal: %d", dec);
    return 0;
}