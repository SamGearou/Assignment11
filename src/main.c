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
  FILE* fp = fopen("animals.tree", "r+");

if(fp == NULL){
  printf("IN HERE\n");
  fp = fopen("animals.tree", "w+");
  fputs("Aelephant", fp);
}
  //char line[MAX_STRING_SIZE];
  //printf("%s\n", fgets(line, MAX_STRING_SIZE, fp));
  //char c = fgetc(stdin);
  //printf("%c\n", c);

  //play(fp, fp);
  //char* val;
  binary_tree* obj = binary_tree_create_f(fp);
  //printf("%s\n", binary_tree_get_string(binary_tree_get_right(obj), val));
// // printf("%s\n", binary_tree_get_string(binary_tree_get_left(obj), val));
// binary_tree* left = binary_tree_get_left(obj);
// if(binary_tree_is_leaf(binary_tree_get_left(left))){
//   printf("THIS IS A LEAF\n");
// }
//binary_tree_destroy(obj);
 //char* val = "Hello";
//char* ok;
 //binary_tree* obj = binary_tree_create_f(fp);
 //printf("%s\n", binary_tree_get_string(obj, ok));
 //binary_tree_destroy(obj);

  //long ans = getEndOfFile(fp);
 // printf("%d\n", ans);
  return EXIT_SUCCESS;
}
