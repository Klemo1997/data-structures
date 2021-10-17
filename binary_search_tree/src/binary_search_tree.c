#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

struct TreeNode* binary_search_tree_create_node(const int data) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void binary_search_tree_destroy_node(struct TreeNode* node) {
    node->left = NULL;
    node->right = NULL;

    free(node);
}

void binary_search_tree_insert(struct TreeNode** root, const int data) {
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

struct TreeNode* binary_search_tree_search(struct TreeNode* root, const int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data == root->data) {
        return root;
    }

    return data < root->data
        ? binary_search_tree_search(root->left, data)
        : binary_search_tree_search(root->right, data);
}

struct TreeNode* binary_search_tree_iterative_search(struct TreeNode* root, const int data) {
    while (root != NULL) {
        if (data == root->data) {
            return root;
        }

        if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}

struct TreeNode* get_min_value(struct TreeNode* root) {
    struct TreeNode* current_node = root;

    while (current_node != NULL && current_node->left != NULL) {
        current_node = current_node->left;
    }

    return current_node;
}

/**
 * Recursive delete helper method
 */
struct TreeNode* node_delete(struct TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    // If the data is less than root,
    // move into the left subtree
    if (data < root->data) {
        root->left = node_delete(root->left, data);
        return root;
    }

    // If the data is larger than root,
    // move into the right subtree
    if (data > root->data) {
        root->right = node_delete(root->right, data);
        return root;
    }
    // If root has no left child, swap them
    // and delete root
    if (root->left == NULL) {
        struct TreeNode* temp = root->right;

        binary_search_tree_destroy_node(root);

        return temp;
    }
    // If root has no right child, but has the left one
    // swap it with root and delete root
    else if (root->right == NULL) {
        struct TreeNode* temp = root->left;

        binary_search_tree_destroy_node(root);

        return temp;
    }

    // If the root has both children, find the
    // closest value in right subtree (the inorder successor)
    struct TreeNode* temp = get_min_value(root->right);

    // Swap it with root
    root->data = temp->data;

    // And delete the inorder successor
    root->right = node_delete(root->right, temp->data);

    return root;
}

void binary_search_tree_delete(struct TreeNode** root, int data) {
    *root = node_delete(*root, data);
}