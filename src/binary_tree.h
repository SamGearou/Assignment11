
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX_STRING_SIZE 1000

typedef struct binary_tree binary_tree;


/**
* @brief creates an empty tree
* @return the tree
*/
binary_tree* binary_tree_create();

/**
* @brief creates a root with no children
* @param [out] str a pointer that stores the value of the root
* @pre str is not NULL
* @return the root
*/
binary_tree* binary_tree_create_s(char* str);

/**
* @brief creates a root with two children
* @param [out] str a pointer that stores the value of the root
* @param left the left child of root
* @param right the right child of root
* @pre str is not NULL
* @return the entire tree
*/
binary_tree* binary_tree_create_stt(char* str, binary_tree* left, binary_tree* right);

/**
* @brief destroys all of the nodes of a tree
* @param self the tree that is to be destroyed
* @pre the binary tree is not empty
*/
void binary_tree_destroy(binary_tree* self);

/**
* @brief sets the left child of self
* @param self the node for which you want to set its left child
* @param left the left child of self
* @pre the binary tree is not empty
*/
void binary_tree_set_left(binary_tree* self, binary_tree* left);

/**
* @brief sets the right child of self
* @param self the node for which you want to set its right child
* @param left the right child of self
* @pre the binary tree is not empty
*/
void binary_tree_set_right(binary_tree* self, binary_tree* right);

/**
* @brief checks to see if a tree is empty
* @return true if the tree is empty
*/
bool binary_tree_is_empty(binary_tree* self);

/**
* @brief checks to see if the node is a leaf
* @return true if the node is a leaf
*/
bool binary_tree_is_leaf(binary_tree* self);

/**
* @brief checks to see if the node is a left child of self
* @param self the node that is to be checked to see if it is a left child
* @return true if the node is a left child
*/
bool binary_tree_is_left(binary_tree* self);

/**
* @brief checks to see if the node is a right child of self
* @param self the node that is to be checked to see if it is a right child
* @return true if the node is a right child
*/
bool binary_tree_is_right(binary_tree* self);

/**
* @brief checks to see if the node is root
* @param self the node that is to be checked to see if it is a root
* @return true if the node is a root
*/
bool binary_tree_is_root(binary_tree* self);

/**
* @brief gets the height of the tree
* @param self the tree that you want to check the height of
* @return the height of the tree
*/
int binary_tree_height(binary_tree* self);

/**
* @brief gets the depth of the tree
* @param self the tree that you want to see what depth it is at
* @return the depth of the tree
*/
int binary_tree_depth(binary_tree* self);

/**
* @brief gets the value of the specified node
* @param [out] str a pointer that stores the value of the node
* @pre str is not NULL
* @return the value of the specified node
*/
char* binary_tree_get_string(binary_tree* self, char* str);

/**
* @brief gets the left child of self
* @param self the parent of the left child
* @return the left child of self
*/
binary_tree* binary_tree_get_left(binary_tree* self);

/**
* @brief gets the right child of self
* @param self the parent of the right child
* @return the rights child of self
*/
binary_tree* binary_tree_get_right(binary_tree* self);

/**
* @brief gets the parent of self
* @param self the child of a specific parent
* @return the parent of self
*/
binary_tree* binary_tree_get_parent(binary_tree* self);

/**
* @brief gets the root of a tree
* @param self a specific node in the tree
* @return the root of the tree
*/
binary_tree* binary_tree_get_root(binary_tree* self);


#endif//__BINARY_TREE_H__
