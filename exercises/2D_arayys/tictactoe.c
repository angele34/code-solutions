/*
Problem #16: Tic Tac Toe
Write a function whoWonTicTacToe which accepts a 2-D 3 × 3 character array.
Each element contains either a 'O', 'X', or '.' representing the current state 
of a tic-tac-toe game ('.' means that the space is still empty).
The function should return the winner of the game ('O' or 'X'). 
If there is no winner yet, or it is a draw, the function should return 'N'. 
Assume that the tic-tac-toe board state is always valid and there is always at most one winner only.
*/

#include <stdio.h>
#define SIZE 3

char whoWonTicTacToe(char game[][SIZE]) {
    printf("Enter a Tic Tac Toe board game: \n");
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf(" %c", &game[i][j]);
        }
    }
    // Check horizontally
    for (i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE-2; j++) {
            // Check if O has won
            if (game[i][j] == 'O' && game[i][j+1] == 'O' && game[i][j+2] == 'O')
                return 'O';
            // Check if X has won
            if (game[i][j] == 'X' && game[i][j+1] == 'X' && game[i][j+2] == 'X')
                return 'X';     
        }
    }
    // Check vertically
    for (i = 0; i < SIZE-2; i++) {
        for (j = 0; j < SIZE; j++) {
            if (game[i][j] == 'O' && game[i+1][j] == 'O' && game[i+2][j] == 'O')
                return 'O';
            if (game[i][j] == 'X' && game[i+1][j] == 'X' && game[i+2][j] == 'X')
                return 'X';
        }
    }
    // Check diagonally top left to bottom right
    for (i = 0; i < SIZE-2; i++) {
        for (j = 0; j < SIZE-2; j++) {
            if (game[i][j] == 'O' && game[i+1][j+1] == 'O' && game[i+2][j+2] == 'O')
                return 'O';
            if (game[i][j] == 'X' && game[i+1][j+1] == 'X' && game[i+2][j+2] == 'X')
                return 'X';
        }
    }
    // Check diagonally top right to bottom left
    for (i = 2; i < SIZE; i++) {
        for (j = 0; j < SIZE-2; j++) {
            if (game[i][j] == 'O' && game[i+1][j+1] == 'O' && game[i+2][j+2] == 'O')
                return 'O';
            if (game[i][j] == 'X' && game[i+1][j+1] == 'X' && game[i+2][j+2] == 'X')
                return 'X';
        }
    }
    return 'N';
}

int main() {
    char game[SIZE][SIZE], winner;
    winner = whoWonTicTacToe(game);
    if (winner == 'O' || winner == 'X')
        printf("\nWinner: %c\n", winner);
    else 
        printf("\n%c\n", winner);
}