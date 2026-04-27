/*
    02-QUEENS
    main.c
    V1.0

    Contains the main function

    NAME:
    SECTION:
*/


/*
    ############
    INSTRUCTIONS
    ############

    Change the file here into the file with your own last name.
    Example: "queens-mendoza.c"
*/
#include "queens-lastname.c"


/*
    You do NOT need to edit the contents of this function.
    The main() function will make use of the function prototypes that you will define.
*/
int
main()
{
    char board[SIZE][SIZE];
    

    InputBoard(board);


    MarkQueensPaths(board);


    InvertBoard(board);


    printf("\n");
    PrintBoard(board);
}