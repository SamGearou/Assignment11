// TODO: Implement the methods in binary_tree_io.c.

#include "binary_tree_io.h"
#include <stdio.h>
#include "binary_tree.h"


void binary_tree_write(binary_tree* self, FILE* stream){
  toFileHelper(self, stream);
}

binary_tree* binary_tree_create_f(FILE* stream){
  return readFileHelper(stream);
}

binary_tree* readFileHelper(FILE* stream){
  char *line;
  if(fgets(line, 1000, stream) != NULL){//change second parameter
  char c = fgetc(stream);
  fgets(line, 1000, stream);
  if(c == 'Q'){
    return binary_tree_create_stt(line, readFileHelper(stream), readFileHelper(stream));
  }
  else if(c == 'A'){
    return binary_tree_create_s(line);
  }
  }
}

void toFileHelper(binary_tree* self, FILE* stream){

}
