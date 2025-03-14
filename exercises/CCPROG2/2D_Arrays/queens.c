/*
Problem #20: Queens
Consider an 8 × 8 chessboard, where there are several queens. We want to check if any pairs of queens are
in range of attacking one another. Write a function checkQueens which accepts an 8 × 8 integer array. 
The integer array can either contain 0, if it is an empty cell, or 1 if there is a queen on that cell. 
The function should return 1 if no two queens can attack each other, or 0 otherwise. 
A queen can attack in a straight line horizontally, vertically, or along the two diagonal directions.
*/
#include <stdio.h>
#define SIZE 8

int checkQueens(int board[][SIZE]) {
    int i,j;
    // Check horizontally
    for (i = 0; i < SIZE; i++) {
        int count = 0; // resets every row
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) 
               count++;
        }
        if (count > 1) 
            return 0;
    }
    // Check vertically
    for (j = 0; j < SIZE; j++) {
        int count = 0;
        for (i = 0; i < SIZE; i++) {
            if (board[i][j] == 1) {
                count++;
            }
        }
        if (count > 1) 
            return 0;
    }
    // Check diagonals
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                // Top left to bottom right
                for (int c = i+1, k = j+1; c < SIZE && k < SIZE; c++, k++) {
                    if (board[c][j] == 1) 
                        return 0;
                }
                for (int c = i-1, k = j-1; c >= 0 && k >= 0; c--, k--) {
                    if (board[c][j] == 1) 
                        return 0;
                }
                // Top right to bottom left
                for (int c = i+1, k = j-1; c < SIZE && k >= 0; c++, k--) {
                    if (board[c][j] == 1) 
                        return 0;
                }
                for (int c = i-1, k = j+1; c >= 0 && k >= SIZE; c--, k++) {
                    if (board[c][j] == 1) 
                        return 0;
                }
                
            }
        }
    }
    return 1;
}

int main() {
    int queens[SIZE][SIZE];
    int i,j;
    printf("Enter an 8 by 8 Chessboard: \n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &queens[i][j]);
        }
    }
    int canAttack = checkQueens(queens);
    if (canAttack == 1) 
        printf("No two queens can attack each other\n");
    else    
        printf("There are two queens that can attack each other\n");
    return 0;
}