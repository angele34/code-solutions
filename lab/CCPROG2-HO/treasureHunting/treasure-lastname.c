/*
    01-TREASURE
    treasure-lastname.c
    V1.0

    Contains the function prototypes that you must define

    NAME:
    SECTION:
*/


/*
    ############
    INSTRUCTIONS
    ############

    1. Strictly follow the function prototypes defined in <treasure.h>.
    2. Use only the libraries defined in <treasure.h>.
    3. Do not define another main() function in this file. It is already defined in <main.c>.
*/


#include "treasure.h"


/*
    FUNCTION 1: PrintBoard()

    This function simply prints the board in the format
    specified in the sample runs.
    
        1  2  3  4  5  6  7  8  9 10
     1  .  .  .  .  .  .  .  .  .  .
     2  .  .  .  .  .  .  .  .  .  .
     3  .  .  .  .  .  .  .  .  .  .
     4  .  .  .  .  .  .  .  .  .  .
     5  .  .  .  .  .  .  .  .  .  .
     6  .  .  .  .  .  .  .  .  .  .
     7  .  .  .  .  .  .  .  .  .  .
     8  .  .  .  .  .  .  .  .  .  .
     9  .  .  .  .  .  .  .  .  .  .
    10  .  .  .  .  .  .  .  .  .  .

    Unlike the other functions, please follow
    the formatting for this table!

    Note that:
    1. Each row and column is numbered.
    2. To make appropriate space for these numbers,
       especially for the columns, each space on the
       board has 2 spaces between them horizontally.
       There are no spaces between the spaces vertically.
    3. Each number has 2-digit padding. The numbers located
       along the top row have their rightmost digit
       aligned with a column.
*/
void 
PrintBoard(char board[][SIZE]) 
{   
    int i,j;
    printf("   ");
    for (i = 0; i < SIZE; i++) {
        printf("%2d  ", i+1);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i+1);
        for (j = 0; j < SIZE; j++) {
            printf("%2c  ", board[i][j]);
        }
        printf("\n");
    }   
}


/*
    FUNCTION 2: GetCoordinates()

    This function simply asks the user for their guessed coordinates.
    The user's input will be in the format "<X> <Y>".

    Example: 
        "1 6" means the guessed coordinates are (1, 6).


    Do note that the coordinates refer to the board, 
    NOT to the indices of the elements.

    Example: 
        "5 5" refers to the element at board[4][4], or board[5-1][5-1].


    If the user inputs coordinates that are out-of-bounds,
    the function will print an error and ask the user to
    input their guessed coordinates again.

    Example: 
        "-1 -6" and "50 80" will both print an error.
        "0 0" and "11 11" will both print an error.
        "1 1" and "10 10" are both valid.

    Note that you may write the error message any way you'd like!
    

    If the user inputs coordinates that were already guessed,
    the function will print an error and ask the user to
    input their guessed coordinates again.

    (Assume that (5, 5) has already been guessed)
    Example:
        "5 5" will print an error.
        "6 6" is valid.

    Note that you may write the error message any way you'd like!
*/
void 
GetCoordinates(char board[][SIZE], int *guessX, int *guessY) 
{   
    int error;
    do {
        printf("Input coordinates (X Y): ");
        scanf("%d %d", guessX, guessY);
        error = 0;
        if (*guessX < 1 || *guessX > SIZE || *guessY < 1 || *guessY > SIZE) {
            printf("Error: Coordinates out of bounds! Try again.\n");
            error = 1;
        } 
        else if (board[*guessY-1][*guessX-1] == 'X') { // Check for already guessed
            printf("Error: You've already guessed (%d, %d)! Try again.\n", *guessX, *guessY);
            error = 1;
        }
    } while (error);
}


/*
    FUNCTION 3: DigAtPoint()

    This function marks spot at the 
    user's guessed coordinates with an 'X'.


    If the user's guessed coordinates match
    the treasure's coordinates, then the
    function returns 1.

    Otherwise, the function will return 0.
*/
int 
DigAtPoint(char board[][SIZE], int guessX, int guessY, int treasureX, int treasureY) 
{
    board[guessY-1][guessX-1] = 'X';
    if (board[guessY-1][guessX-1] == board[treasureY-1][treasureX-1])
        return 1;
    return 0;
}


/*
    FUNCTION 4: GetTreasureDistance()

    This function calculates and returns 
    the distance between treasure and
    the user's guessed coordinates.


    In the context of this program, the distance
    refers to the number of steps needed to be
    brought from point X to point Y, ignoring
    diagonal movement (i.e. going from [0][0] to [1][1]).

    
    Example #1:
    The distance between 'X' and 'Y'
    in the board below is 3.

       1  2  3  4  5
    1  .  .  .  .  .
    2  .  .  .  .  .
    3  .  .  Y  .  .
    4  .  .  .  .  .
    5  .  X  .  .  .

    Path:

       1  2  3  4  5
    1  .  .  .  .  .
    2  .  .  .  .  .
    3  .  . [3] .  .
    4  .  . [2] .  .
    5  . [0][1] .  .


    Example #2:
    The distance between 'X' and 'Y'
    in the board below is 6.

       1  2  3  4  5
    1  .  .  .  Y  .
    2  .  .  .  .  .
    3  .  .  .  .  .
    4  .  .  .  .  .
    5  .  X  .  .  .

    Path:

       1  2  3  4  5
    1  .  .  . [6] .
    2  .  .  . [5] .
    3  .  .  . [4] .
    4  .  .  . [3] .
    5  . [0][1][2] .


    Example #3:
    The distance between 'X' and 'Y'
    in the board below is 7.

       1  2  3  4  5
    1  .  .  .  Y  .
    2  .  .  .  .  .
    3  .  .  .  .  .
    4  .  .  .  .  .
    5  X  .  .  .  .

    Path:

       1  2  3  4  5
    1  .  .  . [7] .
    2  .  .  . [6] .
    3  .  .  . [5] .
    4  .  .  . [4] .
    5 [0][1][2][3] .
*/
int 
GetTreasureDistance(int guessX, int guessY, int treasureX, int treasureY) 
{
    return abs(guessX - treasureX) + abs(guessY - treasureY);
}
