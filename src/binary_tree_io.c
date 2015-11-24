// TODO: Implement the methods in binary_tree_io.h.


#include "binary_tree_io.h"
#include <stdio.h>


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
    return binary_tree_create_stt(line, readFileHelper(stream), readFileHelper(stream));
  }
  else if(c == 'A'){
    return binary_tree_create_s(line);
  }
  else if(c != 'A' && c != 'Q'){
    return binary_tree_create();
  }
  }
  else if(fgets(line, MAX_STRING_SIZE, stream) == NULL){
    fclose(stream);
    return binary_tree_create();
  }
  else{
    printf("In the last block\n");
    fclose(stream);
    return NULL;
  }
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
