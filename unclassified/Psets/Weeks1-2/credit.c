#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main(void) {
    long num = get_long("Number: ");
    long credit = num;
    // multiply every other digit starting from the second last digit by 2
    long remaining = 0, product = 0;
    int i = 1;
    while (num > 0) {
        long last_digit = num % 10;
        // remove the last digit, add in remaining
        num/=10;
        if (i % 2 == 1) {
            remaining += last_digit;
        } else {
            // get every other digit
            last_digit *= 2;
            if (last_digit > 9) {
                while (last_digit > 0) {
                    int n = last_digit % 10;
                    product += n;
                    last_digit/=10;
                }
            } else {
                product += last_digit;
            }
        }
        i++;
    }
    i--;
    product+=remaining;

    if (product % 10 == 0) {
        if (i == 15 && (credit / 10000000000000 == 34 || credit / 10000000000000 == 37)) {
            printf("%s\n", "AMEX");
        } else if (i == 16 && (credit / 100000000000000 >= 51 && credit / 100000000000000 <= 55)) {
            printf("%s\n", "MASTERCARD");
        } else if ((i == 13 || i == 16) && ((credit / 1000000000000000 == 4) || (credit / 1000000000000 == 4))){
            printf("%s\n", "VISA");
        } else {
            printf("%s\n", "INVALID");
        }
    } else {
        printf("%s\n", "INVALID");
    }
}
