#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int length = 0;
    for(int i = n; n > 0; i++) {
        n /= 10;
        length++;
    }
    printf("The length of the number is %d", length);
    return 0;
}
