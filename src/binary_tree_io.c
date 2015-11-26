// TODO: Implement the methods in binary_tree_io.h.


#include "binary_tree_io.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int num = -1;
int* i = &num;
int nums = -1;
int* j = &nums;
bool isInorder;
bool* ok = &isInorder;

void binary_tree_write(binary_tree* self, FILE* stream){
  toFileHelper(self, stream);
}

binary_tree* binary_tree_create_f(FILE* stream){
  return readFileHelper(stream);
}

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
bool isInPreorder(FILE* stream, binary_tree* self) {
  binary_tree* tree = readFileHelper(stream);
  char* val;
  char value[MAX_STRING_SIZE];
  if(tree != NULL){
    strcpy(value, binary_tree_get_string(tree, val));
    if(value[strlen(value)-2] == '?'){
    if(binary_tree_get_left(tree) != NULL && binary_tree_get_right(tree) != NULL){

    }
  }
  }
}

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
