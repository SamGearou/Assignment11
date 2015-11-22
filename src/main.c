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
  binary_tree* left;
  binary_tree* right;
  char* str = "Hello";
  binary_tree *obj = binary_tree_create_stt(str, left, right);
  binary_tree_destroy(obj);
  // if(binary_tree_is_empty(obj)){
  //   printf("Is Empty");
  // }
  // else{
  //   printf("Is not Empty");
  // }
  return EXIT_SUCCESS;
}
