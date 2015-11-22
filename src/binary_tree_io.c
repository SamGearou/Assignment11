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
  char *line;
  if(fgets(line, 6, stream) != NULL && !feof(stream)){//change second parameter
  fgets(line, 1000, stream);
  if(c == 'Q'){
    return binary_tree_create_stt(line, readFileHelper(stream), readFileHelper(stream));
  }
  else if(c == 'A'){
    return binary_tree_create_s(line);
  }
  }
  else if(fgets(line, 1000, stream) == NULL || c != 'A' || c!= 'Q'){
    fclose(stream);
    return NULL;
  }
  else{
    fclose(stream);
    return NULL;
  }
}

void toFileHelper(binary_tree* self, FILE* stream){
if(binary_tree_is_leaf(self)){
fputs(self->value, stream);
}
else{
fputs(self->value, stream);
toFileHelper(binary_tree_get_left(self->left), stream);
toFileHelper(binary_tree_get_right(self->right), stream);
}
}
