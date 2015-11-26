#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "binary_tree_io.h"
#include "animal_game.h"

binary_tree* parent; //the parent of the current node
binary_tree* newTree; //the newTree that is constructed before the initialization of a new game

void play(FILE* inputFile){
  if(inputFile == NULL){
    printf("IN HERE\n");
    inputFile = fopen("src/animals.tree", "w+");
    fputs("Aelephant", inputFile);
    rewind(inputFile);
  }
  binary_tree* tree = binary_tree_create_f(inputFile);
  if(inputFile != NULL){
  printf("Welcome to the Animals game!\n"); //starts the game
  printf("\n");
  printf("Shall we play a game? "); //asks to play
  char c;
  scanf(" %c", &c); //scans for either a 'y' or 'n' char
  while(c == 'y'){
    char* val;
    tree = playRound(inputFile, tree); //plays the game
    printf("\n");
    printf("Shall we play a game? "); //asks to play
    scanf(" %c", &c); //scans for either a 'y' or 'n' char
  }
  printf("Bye!\n"); //quits the game
  freopen("src/animals.tree", "w", inputFile); //makes a blank file to be written to
  binary_tree_write(tree, inputFile); //writes the new information to the file
  rewind(inputFile); //rewinds to the beginning of the file
  fclose(inputFile); //closes the file
  binary_tree_destroy(tree); //free's the malloc'ed memory
  return;
}
else{
  printf("File is null or not in the correct format\n");
}
}

binary_tree* playRound(FILE* stream, binary_tree* tree){
  char answer; //the answer to the question shown
  binary_tree* root = tree;
  char* value;
  char testing[MAX_STRING_SIZE];
  while(!binary_tree_is_leaf(tree)){
    strcpy(testing, binary_tree_get_string(tree, value));
    if(testing[strlen(testing)-1] == '\n'){
      testing[strlen(testing)-1] = '\0';
    }
    printf("%s ", testing);
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
  char finalAnswer; //the answer to the question prompted
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
    scanf("%s", animal); //scans stdin for your animal
    printf("What question separates %s from %s? ", animal, testing3);
    rewind(stdin);
    fgets(question, MAX_STRING_SIZE, stdin); //scans stdin for your question that must end in a '?' char
    printf("What is the correct answer for this animal? ");
    rewind(stdin);
    scanf("%s", correctAnswer); //the correctAnswer to your question
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
