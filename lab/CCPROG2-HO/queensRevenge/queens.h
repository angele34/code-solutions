/*
    02-QUEENS
    queens.h
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


#define SIZE 8


void InputBoard(char board[][SIZE]);


void MarkQueensPaths(char board[][SIZE]);


void InvertBoard(char board[][SIZE]);


void PrintBoard(char board[][SIZE]);