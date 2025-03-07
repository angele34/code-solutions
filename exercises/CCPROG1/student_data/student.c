#include <stdio.h>

int main() {
    char cFirstInitial, cLastInitial;
    int nAge;
    printf("Enter First Name Initial: ");
    scanf("%c", &cFirstInitial);
    printf("Enter Last Name Initial: ");
    scanf(" %c", &cLastInitial);
    printf("Age: ");
    scanf("%d", &nAge);
    printf("Student Record: %c%c 0%d", cFirstInitial, cLastInitial, nAge);
    return 0;
}