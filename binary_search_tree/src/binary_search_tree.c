#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

struct TreeNode* binary_search_tree_create_node(int data) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void binary_search_tree_insert(struct TreeNode** root, int data) {
    // If the tree has no root
    // assign new node as root
    if (*root == NULL) {
        *root = binary_search_tree_create_node(data);
        return;
    }

    // if root data is same as data to add
    // we do not add duplicity entry
    // otherwise we continue to particular subtree
    if (data < (*root)->data) {
        if ((*root)->left == NULL) {
            (*root)->left = binary_search_tree_create_node(data);
            return;
        }

        binary_search_tree_insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        if ((*root)->right == NULL) {
            (*root)->right = binary_search_tree_create_node(data);
            return;
        }

        binary_search_tree_insert(&(*root)->right, data);
    }
}