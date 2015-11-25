#ifndef __ANIMAL_GAME_C__
#define __ANIMAL_GAME_C__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
*@brief the main method that plays the game
*/
void play(FILE* inputFile, FILE* outputFile);

binary_tree* playRound(FILE* stream, binary_tree* tree);

#endif//__ANIMAL_GAME_C__
