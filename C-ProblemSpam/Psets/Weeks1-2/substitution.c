#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* substitute(string k);

int main(int argc, string argv[]) {
    string k;

    if (argc != 2) {
        printf("Usage: ./substitution KEY\n");
        return 1;
    } else {
        int n = strlen(argv[1]);
        if (n != 26) {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (!isalpha(argv[1][i])) {
                printf("Key must only contain alphabetic characters\n");
                return 1;
            }
        }

        char repeat[26] = {0};
        for (int i = 0; i < n; i++) {
            char temp = toupper(argv[1][i]);
            int index = (temp - 'A');
            repeat[index]++;
            if (repeat[index] > 1) {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    k = argv[1];
    char* ciphertext = substitute(k);
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}

char* substitute(string k) {
    string plaintext = get_string("plaintext: ");

    int n = strlen(plaintext);
    char* ciphertext = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        if (isupper(plaintext[i])) {
            int index = plaintext[i] - 'A';
            ciphertext[i] = toupper(k[index]);
        } else if (islower(plaintext[i])) {
            int index = plaintext[i] - 'a';
            ciphertext[i] = tolower(k[index]);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
    return ciphertext;
}
