/*
    01-TREASURE
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
    Example: "treasure-mendoza.c"
*/
#include "treasure-lastname.c"


/*
    You do NOT need to edit the contents of this function.
    This function sets the treasure to a randomized position on the board.
*/
void 
SetTreasure(int *treasureX, int *treasureY) 
{
    *treasureX = (rand() % SIZE) + 1;
    *treasureY = (rand() % SIZE) + 1;
    
    // *treasureX = 5;
    // *treasureY = 5;
}


/*
    You do NOT need to edit the contents of this function.
    The main() function will make use of the function prototypes that you will define.
*/
int 
main() 
{
    char board[SIZE][SIZE] =
    {
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
        '.','.','.','.','.','.','.','.','.','.',
    };

    int triesLeft = TRIES;
    int treasureX, treasureY;
    int guessX, guessY;
    int distance;
    int found = 0;

    // Sets the treasure at a randomized position on the board
    srand(time(NULL));
    SetTreasure(&treasureX, &treasureY);

    // While the treasure isn't found yet
    // AND the user still has tries left...
    while (!found && triesLeft > 0) 
    {
        PrintBoard(board);

        // Prints how many tries the user has left
        printf("Tries left: %d\n", triesLeft);

        // Gets the user's guessed coordinates
        GetCoordinates(board, &guessX, &guessY);

        // Checks if the user found the treasure
        found = DigAtPoint(board, guessX, guessY, treasureX, treasureY);

        // If the treasure wasn't found...
        if (!found) 
        {
            // Calculate then print the distance
            distance = GetTreasureDistance(guessX, guessY, treasureX, treasureY);
            printf("\n\"The treasure is %d space/s away, lad...\"\n\n", distance);

            // Decrease the user's current tries
            triesLeft--;
        }
        // If it was, the while loop gets exited here
        // Otherwise, return back to the start of the loop,
        // until the user runs out of tries (i.e. tries reach 0).
    }
    
    // If the treasure was found...
    if (found) 
    {
        PrintBoard(board);
        printf("\"Yarr... You win!\"\n");
    
    }
    // If not...
    else 
    {
        PrintBoard(board);
        printf("\"Yarr... The treasure was at (%d, %d)!", treasureX, treasureY);
        printf("\nBetter luck next time, kid!\"\n");
    }
    
    return 0;
}