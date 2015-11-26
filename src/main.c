// TODO: Add Javadoc style header

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"
#include "animal_game.h"
#include <string.h>

int main()
{
  FILE* fp = fopen("src/animals.tree", "r+");

  play(fp);


  return EXIT_SUCCESS;
}
