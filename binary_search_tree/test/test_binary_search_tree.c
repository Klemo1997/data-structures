#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "binary_search_tree.h"

CHEAT_TEST(binary_search_tree_insertion_to_empty_tree,
    struct TreeNode *root = NULL;
    binary_search_tree_insert(&root, 2);

    cheat_assert_int(root->data, 2);
)

CHEAT_TEST(binary_search_tree_insertion_multiple_inserts,
    struct TreeNode *root = NULL;
    binary_search_tree_insert(&root, 2);
    binary_search_tree_insert(&root, 1);
    binary_search_tree_insert(&root, 3);

    cheat_assert_int(root->data, 2);
    cheat_assert_int(root->left->data, 1);
    cheat_assert_int(root->right->data, 3);
)

CHEAT_TEST(binary_search_tree_insertion_does_not_add_duplicates,
    struct TreeNode *root = NULL;
    binary_search_tree_insert(&root, 2);
    binary_search_tree_insert(&root, 2);

    cheat_assert_int(root->data, 2);
    cheat_assert(root->left == NULL);
    cheat_assert(root->right == NULL);
)