#ifndef __BINARY_TREE_IO_H__
#define __BINARY_TREE_IO_H__

#include <stdio.h>
#include "binary_tree.h"


/**
* @brief writes inputs to a file
* @param self the tree that you want to write information to
* @param stream the file that you are writing to
*
*/
void binary_tree_write(binary_tree* self, FILE* stream);


/**
* @brief reads in input from a file
* @param stream the file you are reading from
 * *return the tree that is created from the read file
*/
binary_tree* binary_tree_create_f(FILE* stream);

#endif//__BINARY_TREE_IO_H__
