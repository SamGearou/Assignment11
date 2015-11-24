// TODO: Add Javadoc style header

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include "binary_tree_io.h"
#include "animal_game.h"
#include <string.h>
// TODO: You will probably need to add more includes...

// Program entry point

// void play(FILE* inputFile, FILE* outputFile){
//   printf("Welcome to the Animals game!\n");
//   printf("\n");
//   printf("Do you want to play a game? y to play, n to not play\n");
//   printf("\n");
//   char yesOrNo[0];
//   scanf("%s\n" yesOr);
//   printf("The value of yesOrNo is: %c\n", yesOrNo);
// }
int main()
{
  FILE* fp = fopen("Ok.txt", "r");
  //char line[MAX_STRING_SIZE];
  //printf("%s\n", fgets(line, MAX_STRING_SIZE, fp));
  //char c = fgetc(stdin);
  //printf("%c\n", c);


  //play(fp, NULL);
  binary_tree* obj = binary_tree_create_f(fp);
  char* value;
  printf("%s\n", binary_tree_get_string(obj, value));

  return EXIT_SUCCESS;
}
