#include "binary_tree.h"

// We have provided you with the binary tree struct. This struct must not be
// changed. You should implement the binary tree functions declared in
// binary_tree.h, and any helper functions you would like in this file.

binary_tree* binary_tree_create(){
  binary_tree* bTree = malloc(sizeof(binary_tree));
  bTree->parent = NULL;
  bTree->left = NULL;
  bTree->right = NULL;
  return bTree;
}
