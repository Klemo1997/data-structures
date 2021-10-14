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

struct TreeNode* binary_search_tree_create_node(int data);

void binary_search_tree_insert(struct TreeNode** root, int data);

#endif _LINKED_LIST_H_