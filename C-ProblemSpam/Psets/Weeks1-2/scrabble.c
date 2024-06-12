#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void) {
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    if (score1 > score2) {
        printf("%s\n", "Player 1 wins!");
    } else if (score1 < score2) {
        printf("%s\n", "Player 2 wins!");
    } else {
        printf("%s\n", "Tie!");
    }
}

int compute_score(string word) {
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        if(isupper(word[i])) {
            score += POINTS[word[i] - 'A'];
        } else if (islower(word[i])) {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
