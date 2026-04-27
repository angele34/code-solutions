/*
    01-TREASURE
    treasure.h
    V1.0

    Defines the prototypes of the functions
*/


/*
    ############
    INSTRUCTIONS
    ############

    Please DO NOT add or change any values found here!
    This includes the libraries, the values in #define, and the parameter names!
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define SIZE 10 // defines the size of the board
#define TRIES 5 // defines how many total tries are given to the user


void SetTreasure(int *treasureX, int *treasureY);


void PrintBoard(char board[][SIZE]);


void GetCoordinates(char board[][SIZE], int *guessX, int *guessY);


int DigAtPoint(char board[][SIZE], int guessX, int guessY, int treasureX, int treasureY);


int GetTreasureDistance(int guessX, int guessY, int treasureX, int treasureY);