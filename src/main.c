

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"
#include "animal_game.h"
#include <string.h>

/**
* @brief starts the main game loop
*/
int main()
{
  FILE* fp = fopen("src/animals.tree", "r+"); //the file that is to be read 

  play(fp);

  return EXIT_SUCCESS;
}
