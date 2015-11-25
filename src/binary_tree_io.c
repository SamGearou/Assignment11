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
  char c = fgetc(stream);
  char line[MAX_STRING_SIZE];
  if(fgets(line, MAX_STRING_SIZE, stream) != NULL){
    if(c == 'Q'){
      printf("IN Q\n");
      return binary_tree_create_stt(line, readFileHelper(stream), readFileHelper(stream));
    }
    else if(c == 'A'){
      return binary_tree_create_s(line);
    }
    else if(c != 'A' && c != 'Q'){
      printf("NOT IN A OR Q\n");
      fclose(stream);
      return NULL;
    }
  }
  else if(fgets(line, MAX_STRING_SIZE, stream) == NULL){
    ("FGETS NULL\n");
    fclose(stream);
    return NULL;
  }
  else{
    printf("LAST BLOCK\n");
    fclose(stream);
    return NULL;
  }
}
bool isInPreorder(FILE* stream, binary_tree* self) {
  if(isInorder){
    ++*j;
    //printf("%d\n", num);
    //printf("1\n");
    char* value;
    char last;
    char set[MAX_STRING_SIZE];
    strcpy(set, binary_tree_get_string(self, value));
    last=set[strlen(set) - 2];
    //printf("the last: %c\n", set[strlen(set) - 2]);
    //printf("last equals: %c\n", last);
    //printf("Length of set %d\n", strlen(set));
    if (last == '?') {
      printf("2\n");
      if (binary_tree_is_leaf(self)) {
        printf("4\n");
        *ok = false;
        exit(0);
      }
    }
    else if(last != '?') {
      if (binary_tree_is_leaf(self)) {
        if (num==nums) {
          //printf("they are equal\n");
          *ok =true;
        }
        *ok = true;
      }
      printf("5\n");
      if (!binary_tree_is_leaf(self)) {
        printf("6\n");
        *ok = false;
      }
    }
    if (!binary_tree_is_leaf(self)) {
      printf("3\n");
      isInPreorder(stream, binary_tree_get_left(self));
      isInPreorder(stream, binary_tree_get_right(self));
      *ok = true;
    }
  }
  else{
    return false;
  }
  printf("8\n");
}

void toFileHelper(binary_tree* self, FILE* stream){
  if(binary_tree_is_leaf(self)){
    fputs(binary_tree_get_string(self, NULL), stream);
  }
  else{
    fputs(binary_tree_get_string(self, NULL), stream);
    toFileHelper(binary_tree_get_left(self), stream);
    toFileHelper(binary_tree_get_right(self), stream);
  }
}
