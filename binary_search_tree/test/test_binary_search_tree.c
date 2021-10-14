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

CHEAT_TEST(binary_search_tree_search_finds_root,
    struct TreeNode *root = NULL;
    binary_search_tree_insert(&root, 2);

    cheat_assert_int(
       2,
       binary_search_tree_search(root, 2)->data
    );
)

CHEAT_TEST(binary_search_tree_search_finds_recursively,
    struct TreeNode *root = NULL;
    int numbers[3] = {2,1,3};

    for (int i = 0; i < 3; i++) {
       binary_search_tree_insert(&root, numbers[i]);
    }

    for (int i = 0; i < 3; i++) {
       cheat_assert_int(
               numbers[i],
               binary_search_tree_search(root, numbers[i])->data
       );
    }
)

CHEAT_TEST(binary_search_tree_search_returns_null_if_not_found,
    struct TreeNode *root = NULL;
    int numbers[3] = {2,1,3};

    for (int i = 0; i < 3; i++) {
       binary_search_tree_insert(&root, numbers[i]);
    }

    cheat_assert(
       binary_search_tree_search(root, 5) == NULL
    );
)
