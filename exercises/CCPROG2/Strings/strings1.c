#include <stdio.h>
#include <string.h>

/*
Problem 2.2. Implement void PrintReversed (char *str); which will output the string in reversed order. 
For example, the function call PrintReversed ("ABC"); will output "CBA".
*/

void PrintReversed(char *str, char *rev) {
    int len = strlen(str);
    for (int i = len-1; i >= 0; i--) {
        *rev = str[i];
        rev++;
    }
    *rev = '\0';
    printf("Reversed string: %s\n", rev-len);
}

/*
Problem 2.3. Implement int IsPalindrome (char *str); 
which will return a 1 if the string parameter is a palindrome otherwise it returns a 0. 
A palindrome is a word or phrase that when read backwards (or in reversed order) produces the same word or phrase. 
For example, the word "ROTOR" is a palindome. The phrase "STAR RATS" is a palindrome. The word "GOOD CAT" is not a palindrome.
*/

int isPalindrome(char *str, char *rev) {
    int len = strlen(str);
    for (int i = len-1; i >= 0; i--) {
        *rev = str[i];
        rev++;
    }
    *rev = '\0';
    if (strcmp(str,rev-len) == 0) 
        return 1;
    return 0;
}

int main() {
    char str[20], rev[20];
    printf("Enter a string: \n");
    scanf(" %s", str);
    PrintReversed(str,rev);

    int palindrome = isPalindrome(str, rev);

    if (palindrome == 1) 
        printf("%s is a palindrome\n", str);
    else 
        printf("%s is not a palindrome", str);

    return 0;
}