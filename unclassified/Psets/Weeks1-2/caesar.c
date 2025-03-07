#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* caesar(int k);
int main(int argc, string argv[]) {
    bool isDigit = true;
    int k;
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    } else {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) {
            if (!isdigit(argv[1][i])) {
                isDigit = false;
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    k = atoi(argv[1]);
    char* ciphertext = caesar(k);
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}

char* caesar(int k) {
    string plaintext = get_string("Plaintext:  ");
    int n = strlen(plaintext);
    char* ciphertext = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
            } if (islower(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
    return ciphertext;
}
