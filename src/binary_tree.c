

#include "binary_tree.h" //.h

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
  strcpy(bTree->value, "NULL");
  bTree->parent = NULL;
  bTree->left = NULL;
  bTree->right = NULL;
  return bTree;
}

binary_tree* binary_tree_create_s(char* str){
  binary_tree* bTree = malloc(sizeof(binary_tree));
  bTree->parent = NULL;
  bTree->left = binary_tree_create();
  bTree->left->parent = bTree;
  bTree->right = binary_tree_create();
  bTree->right->parent = bTree;
  strcpy(bTree->value, str);
  return bTree;
}

binary_tree* binary_tree_create_stt(char* str, binary_tree* left, binary_tree* right){
  binary_tree* bTree = malloc(sizeof(binary_tree));
  bTree->parent = NULL;
  binary_tree_set_left(bTree, left);
  binary_tree_set_right(bTree, right);
  strcpy(bTree->value, str);
  return bTree;
}

void binary_tree_destroy(binary_tree* self){
  if(self->left != NULL){
    binary_tree_destroy(self->left);
  }
  if(self->right != NULL){
    binary_tree_destroy(self->right);
  }
  free(self);
  self=NULL;
}

void binary_tree_set_left(binary_tree* self, binary_tree* left){//self = parent, check this method!
  if(binary_tree_is_empty(self)){
    return;
  }
  self->left = malloc(sizeof(binary_tree));
  self->left = left;
  left->parent = self;
}

void binary_tree_set_right(binary_tree* self, binary_tree* right){//self = parent, check this method!
  if(binary_tree_is_empty(self)){
    return;
  }
  self->right = malloc(sizeof(binary_tree));
  self->right = right;
  self->right->parent = self;
}

bool binary_tree_is_empty(binary_tree* self){
  if(self->parent == NULL && self->left == NULL && self->right == NULL){
    return true;
  }
  return false;
}

bool binary_tree_is_leaf(binary_tree* self){
  if(strcmp(self->right->value, "NULL") == 0 && strcmp(self->left->value, "NULL") == 0){
    return true;
}
  return false;
}

bool binary_tree_is_left(binary_tree* self){
  if(self->parent == NULL){
    return false;
  }
  if(self->parent == NULL){
    return false;
  }
  return self == binary_tree_get_left(self->parent); //check

}

bool binary_tree_is_right(binary_tree* self){
  if(self->parent == NULL){
    return false;
  }
  return self == binary_tree_get_right(self->parent); //check
}

bool binary_tree_is_root(binary_tree* self){
  if(self->parent == NULL && self->right == NULL && self->left == NULL){
    return true;
  }
  return false;
}

int binary_tree_height(binary_tree* self){
  if(binary_tree_get_left(self) == NULL && binary_tree_get_right(self) == NULL) {
    return 0;
  }
  int greater;
  if(binary_tree_height(self->left) > binary_tree_height(self->right)){
    greater = binary_tree_height(self->left);
  }
  else{
    greater = binary_tree_height(self->right);
  }
  return 1 + greater;
}

int binary_tree_depth(binary_tree* self){
  if(self->parent == NULL){
    return 0;
  }
  return 1 + binary_tree_depth(self->parent);
}

char* binary_tree_get_string(binary_tree* self, char* str){
  return self->value;
}

binary_tree* binary_tree_get_left(binary_tree* self){
  return self->left;
}

binary_tree* binary_tree_get_right(binary_tree* self){
  return self->right;
}

binary_tree* binary_tree_get_parent(binary_tree* self){
  return self->parent;
}

binary_tree* binary_tree_get_root(binary_tree* self){
  if(self->parent == NULL){
    return self;
  }
  return binary_tree_get_root(self->parent);
}
