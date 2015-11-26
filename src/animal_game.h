#ifndef __ANIMAL_GAME_C__
#define __ANIMAL_GAME_C__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



/**
* @brief the main game loop
* @param stream the file that is to be read in
* @param tree the binary_tree that is created from the read file
* @return the new tree that is constructed based on the updated file
*/
binary_tree* playRound(FILE* stream, binary_tree* tree);

/**
*@brief starts the initialization of the game
*@param inputFile the file that is read in and used in the game
*/
void play(FILE* inputFile);

#endif//__ANIMAL_GAME_C__
