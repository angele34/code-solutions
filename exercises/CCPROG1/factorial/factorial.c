#include <stdio.h>

int main() {
    int nFactorial, nSum = 1;
    printf("Enter a number: ");
    scanf("%d", &nFactorial);
    for (int i = nFactorial; i >= 1; i--) {
        nSum *= i;
    }
    printf("The factorial of %d is: %d\n", nFactorial, nSum);
    return 0;
}