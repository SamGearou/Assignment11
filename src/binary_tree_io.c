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

}

binary_tree* toFileHelper(binary_tree* self, FILE* stream){

}
