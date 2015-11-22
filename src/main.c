// TODO: Add Javadoc style header

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include <string.h>
// TODO: You will probably need to add more includes...

// Program entry point
int main()
{
  printf("Welcome to the Animals game!\n");

  // TODO: Add the game...
  char* str = "Hello";
  binary_tree* obj = binary_tree_create_s(str);
  binary_tree* obj2 = binary_tree_create_s(str);
  binary_tree_set_left(obj, obj2);
  printf("%d\n", binary_tree_height(obj));

  return EXIT_SUCCESS;
}
