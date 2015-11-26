
#include "binary_tree_io.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* @brief a helper function that processes information from a file and converts it into a binary tree
* @param stream that file that is read from
* @return the tree that is created from reading the file
*/
binary_tree* readFileHelper(FILE* stream){
  printf("1\n");
  char c = fgetc(stream);
  char line[MAX_STRING_SIZE];
  if(fgets(line, MAX_STRING_SIZE, stream) != NULL){
    printf("2\n");
    if(c == 'Q'){
      return binary_tree_create_stt(line, readFileHelper(stream), readFileHelper(stream));
    }
    else if(c == 'A'){
      printf("WORKING\n");
      return binary_tree_create_s(line);
    }
    else if(c != 'A' && c != 'Q'){
      fclose(stream);
      return NULL;
    }
  }
  else if(fgets(line, MAX_STRING_SIZE, stream) == NULL){
    fclose(stream);
    return NULL;
  }
  else{
    fclose(stream);
    return NULL;
  }
}

/**
* @brief a helper function that writes to a file based on a specific tree
* @param self the tree that is referenced based on the value of its nodes
* @param stream the file to be written to
*/
void toFileHelper(binary_tree* self, FILE* stream){
  if(binary_tree_is_leaf(self)){
    char value[MAX_STRING_SIZE];
    strcpy(value, binary_tree_get_string(self, NULL));
    if(value[strlen(value)-1] != '\n'){
      strcat(value, "\n");
    }
    fputs("A", stream);
    fputs(value, stream);
  }
  else{
    fputs("Q", stream);
    fputs(binary_tree_get_string(self, NULL), stream);
    toFileHelper(binary_tree_get_left(self), stream);
    toFileHelper(binary_tree_get_right(self), stream);
  }
}

void binary_tree_write(binary_tree* self, FILE* stream){
  toFileHelper(self, stream);
}

binary_tree* binary_tree_create_f(FILE* stream){
  return readFileHelper(stream);
}
