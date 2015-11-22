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
const char *str= "Hello";

   binary_tree *obj = binary_tree_create_s(str);
   if(strcmp(obj->value, "Hello") == 0){
     printf("It is NUll\n");
   }
   printf("%s\n", obj->value);
    return EXIT_SUCCESS;
}
