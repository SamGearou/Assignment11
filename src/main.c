// TODO: Add Javadoc style header

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"
#include <string.h>
// TODO: You will probably need to add more includes...

// Program entry point
int main()
{
  printf("Welcome to the Animals game!\n");

  // TODO: Add the game...
FILE* input = fopen("Ok.txt", "r");
binary_tree* obj = binary_tree_create_f(input);
printf("%s\n", binary_tree_get_string(binary_tree_get_right(obj), NULL));

  return EXIT_SUCCESS;
}
