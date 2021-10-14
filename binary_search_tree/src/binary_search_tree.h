#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/**
 * Tree node base structure
 */
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Allocates and returns new Tree node struct
 */
struct TreeNode* binary_search_tree_create_node(int data);

/**
 * Inserts node with given value into Tree
 */
void binary_search_tree_insert(struct TreeNode** root, int data);

/**
 * Search value within binary search tree, if the value does not exist
 * return NULL instead
 */
struct TreeNode* binary_search_tree_search(struct TreeNode* root, int data);

#endif _LINKED_LIST_H_