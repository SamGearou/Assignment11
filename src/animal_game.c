#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "binary_tree_io.h"

void play(FILE* inputFile, FILE* outputFile){
  binary_tree* tree = binary_tree_create_f(inputFile);
  printf("Welcome to the Animals game!\n");
  printf("\n");
  printf("Shall we play a game? ");
  char c = fgetc(stdin);
  //while(c == 'y'){
//tree = playRound()
  //}
}
