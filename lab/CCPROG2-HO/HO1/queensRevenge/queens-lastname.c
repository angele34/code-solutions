/*
    02-QUEENS
    queens-lastname.c
    V1.0

    Contains the function prototypes that you must define

    NAME:
    SECTION:
*/


/*
    ############
    INSTRUCTIONS
    ############

    1. Strictly follow the function prototypes defined in <queens.h>.
    2. Use only the libraries defined in <queens.h>.
    3. Do not define another main() function in this file. It is already defined in <main.c>.
*/


#include "queens.h"


/*
    FUNCTION #1: InputBoard()

    This function asks the user to input
    all 8 rows of the Chess board.

    Inputs should be one continuous string
    of 8 characters without any spaces.
    Example:
        "........"
        "Q...Q.Q."
    
    Formatting won't be too strict, but I
    recommend following it anyway (lol):

    "
    Enter each row of the Chess board:
    > <user input>
    "
*/
void
InputBoard(char board[][SIZE])
{
    int i,j;
    for (i = 0; i < SIZE; i++) {
      scanf("%s", board[i]);
    }
}


/*
    FUNCTION #2: MarkQueensPaths()

    This function marks spaces on the board
    that each queen piece would be able
    to reach.

    A queen piece can see every space along
    both its row and column, as well as
    every space along the diagonals.
    
    * . . . * . . .
    . * . . * . . *
    . . * . * . * .
    . . . * * * . .
    * * * * Q * * *
    . . . * * * . .
    . . * . * . * .
    . * . . * . . *

    Like the rays of a shining sun.
*/
void 
MarkQueensPaths(char board[][SIZE])
{
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 'Q') {
                for (int k = 0; k < SIZE; k++) {
                    if (board[k][j] != 'Q') board[k][j] = '*';
                    if (board[i][k] != 'Q') board[i][k] = '*';
                }

                // check top left to bottom right
                for (int c = i, k = j; c < SIZE && k < SIZE; c++, k++) {
                    if (board[c][k] != 'Q') board[c][k] = '*'; 
                }
                for (int c = i, k = j; c >= 0 && k >= 0; c--, k--) {
                    if (board[c][k] != 'Q') board[c][k] = '*'; 
                }

                // check top right to bottom left
                for (int c = i, k = j; c < SIZE && k >= 0; c++, k--) {
                    if (board[c][k] != 'Q') board[c][k] = '*';  
                }
                for (int c = i, k = j; c >= 0 && k < SIZE; c--, k++) {
                    if (board[c][k] != 'Q') board[c][k] = '*'; 
                }

            }
        } 
    }
}


/*
    FUNCTION #3: InvertBoard()

    This function essential inverts every
    space on the board. Every asterisk '*' character
    will be turned into a dot character '.', and
    every dot character '.' will be turned
    into the character 'X'.

    Example:

    * . . . * . . .
    . * . . * . . *
    . . * . * . * .
    . . . * * * . .
    * * * * Q * * *
    . . . * * * . .
    . . * . * . * .
    . * . . * . . *

    . X X X . X X X
    X . X X . X X .
    X X . X . X . X
    X X X . . . X X
    . . . . Q . . .
    X X X . . . X X
    X X . X . X . X
    X . X X . X X .
*/
void
InvertBoard(char board[][SIZE])
{
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == '*') 
                board[i][j] = '.';
            else if (board[i][j] == '.')
                board[i][j] = 'X';
        }
    }
}


/*
    FUNCTION #4: PrintBoard()

    This function simply prints all
    spaces on the Chess board.

    Please follow the formatting below,
    where each element along the rows
    has 1 space between each other.

    . . . . X . X X
    . Q . . . . . .
    . . . . . . . .
    . . . . . Q . .
    X . X . . . . X
    X . . . . . X .
    . . . Q . . . .
    X . . . . . X .
*/
void 
PrintBoard(char board[][SIZE])
{
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}