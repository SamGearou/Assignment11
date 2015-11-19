#include "binary_tree.h"

// We have provided you with the binary tree struct. This struct must not be
// changed. You should implement the binary tree functions declared in
// binary_tree.h, and any helper functions you would like in this file.

struct binary_tree
{
    char value[MAX_STRING_SIZE];
    binary_tree* left;
    binary_tree* right;
    binary_tree* parent;
};

binary_tree* binary_tree_create(){
  binary_tree* bTree = malloc(sizeof(binary_tree));
  bTree->parent = NULL;
  bTree->left = NULL;
  bTree->right = NULL;
  return bTree;
}



int main() {

printf("%s\n", "WORKING");
  return EXIT_SUCCESS;
}
