#include <stdio.h>
#include <string.h>

void Reverse(char *s1, char *rev) {
    int n = strlen(s1);
    for (int i = n-1; i >= 0; i--) {
        *rev = s1[i];
        rev++;
    }
    *rev = '\0';
    printf("%s", rev-n);
}

int main() {
    char s1[20], rev[20];
    printf("Enter a string: \n");
    scanf("%s", s1);
    Reverse(s1,rev);
    return 0;
}