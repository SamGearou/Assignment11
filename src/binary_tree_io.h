#ifndef __BINARY_TREE_IO_H__
#define __BINARY_TREE_IO_H__

#include <stdio.h>
// TODO: You may want to add additional includes

// TODO: Add Javadoc comments for these functions.


/**
* @brief writes inputs to a file
*
*/
void binary_tree_write(binary_tree* self, FILE* stream);


/**
* @brief reads in input from a file
*
*/
binary_tree* binary_tree_create_f(FILE* stream);

#endif//__BINARY_TREE_IO_H__
