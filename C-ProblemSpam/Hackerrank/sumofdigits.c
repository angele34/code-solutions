#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/problem?isFullScreen=true
*/

int main() {
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    while(n > 0) {
        int last_digit = n%10; // get the last digit
        n/=10; // remove the last digit
        sum+=last_digit;
    }
    printf("%d", sum);
    return 0;
}