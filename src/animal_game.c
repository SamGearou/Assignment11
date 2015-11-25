#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "binary_tree_io.h"
#include "animal_game.h"

binary_tree* parent;
binary_tree* newTree;

void play(FILE* inputFile, FILE* outputFile){
  binary_tree* tree = binary_tree_create_f(inputFile);
  printf("Welcome to the Animals game!\n"); //println
  printf("\n");
  printf("Shall we play a game1? "); //println
  char c;
  scanf(" %c", &c);
  printf("C EQUALS L%cL\n", c);
  while(c == 'y'){
    tree = playRound(inputFile, tree);
    printf("\n");
    printf("Shall we play a game2? "); //println
    scanf(" %c", &c);
  }
  printf("Bye!\n"); //println
  binary_tree_write(tree, outputFile);
  fclose(outputFile);
  binary_tree_destroy(tree);
  return;
}

binary_tree* playRound(FILE* stream, binary_tree* tree){
  char answer;
  binary_tree* root = tree;
  char* value;
  char testing[MAX_STRING_SIZE];
  while(!binary_tree_is_leaf(tree)){
    strcpy(testing, binary_tree_get_string(tree, value));
    if(testing[strlen(testing)-1] == '\n'){
      testing[strlen(testing)-1] = '\0';
    }
    printf("%s ", testing); //println  Does it moo?
    rewind(stdin);
    scanf(" %c", &answer);
    if(answer == 'y'){
      parent = tree;
      tree = binary_tree_get_right(tree);
    }
    else{
      parent = tree;
      tree = binary_tree_get_left(tree);
    }
  }
  if(answer != 'y' && answer != 'n'){
    answer = 's';
  }
  char* val;
  char finalAnswer;
  char testing2[MAX_STRING_SIZE];
  strcpy(testing2, binary_tree_get_string(tree, val));
  if(testing2[strlen(testing2)-1] == '\n'){
    testing2[strlen(testing2)-1] = '\0';
  }
  printf("Were you thinking of a %s ? ", testing2);
  scanf(" %c", &finalAnswer);
  if(finalAnswer == 'y'){
    printf("Great\n");
    return root;
  }
  else{
    printf("Doh! What was the animal? ");
    char animal[MAX_STRING_SIZE];
    char question[MAX_STRING_SIZE];
    char correctAnswer[MAX_STRING_SIZE];
    char* getValue;
    char testing3[MAX_STRING_SIZE];
    strcpy(testing3, binary_tree_get_string(tree, getValue));
    if(testing3[strlen(testing3)-1] == '\n'){
      testing3[strlen(testing3)-1] = '\0';
    }
    scanf("%s", animal);
    printf("What question separates %s from %s? ", animal, testing3);
    rewind(stdin);
    fgets(question, MAX_STRING_SIZE, stdin);
    printf("What is the correct answer for this animal? ");
    rewind(stdin);
    scanf("%s", correctAnswer);
    if(answer == 's'){
      parent= NULL;
    }
    if(correctAnswer == 'y'){
      newTree = binary_tree_create_stt(question, binary_tree_create_s(animal), tree);
    }
    else{
      newTree = binary_tree_create_stt(question, tree, binary_tree_create_s(animal));
    }
    if(answer == 's'){
      printf("this is correct\n");
      return newTree;
    }
    else{
      if(answer == 'y'){
        binary_tree_set_right(parent, newTree);
      }
      else{
        binary_tree_set_left(parent, newTree);
      }
        return root;
    }
  }
}
