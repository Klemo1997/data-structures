#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "binary_search_tree.h"

CHEAT_DECLARE(
        struct TreeNode* get_single_node_tree() {
            struct TreeNode *root = NULL;
            binary_search_tree_insert(&root, 2);

            return root;
        }

        void construct_binary_search_tree(struct TreeNode** root, int data[], int data_size) {
            for (int i = 0; i < data_size; i++) {
                binary_search_tree_insert(root, data[i]);
            }
        }

        struct TreeNode* get_tree_with_children() {
            struct TreeNode *root = NULL;
            int nodes[3] = {2, 1, 3};

            construct_binary_search_tree(&root, nodes, 3);

            return root;
        }
)

CHEAT_TEST(binary_search_tree_insertion_to_empty_tree,
    struct TreeNode *root = get_single_node_tree();

    cheat_assert_int(root->data, 2);
)

CHEAT_TEST(binary_search_tree_insertion_multiple_inserts,
    struct TreeNode *root = get_tree_with_children();

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
    struct TreeNode *root = get_tree_with_children();
    int numbers[3] = {2,1,3};

    for (int i = 0; i < 3; i++) {
       cheat_assert_int(
           numbers[i],
           binary_search_tree_search(root, numbers[i])->data
       );
    }
)

CHEAT_TEST(binary_search_tree_search_returns_null_if_not_found,
    struct TreeNode *root = get_tree_with_children();

    cheat_assert(
       binary_search_tree_search(root, 5) == NULL
    );
)

CHEAT_TEST(binary_search_tree_iterative_search_finds_root,
   struct TreeNode *root = NULL;
   binary_search_tree_insert(&root, 2);

   cheat_assert_int(
       2,
       binary_search_tree_iterative_search(root, 2)->data
   );
)

CHEAT_TEST(binary_search_tree_iterative_search_finds_recursively,
    struct TreeNode *root = get_tree_with_children();
    int numbers[3] = {2,1,3};

    for (int i = 0; i < 3; i++) {
       cheat_assert_int(
           numbers[i],
           binary_search_tree_iterative_search(root, numbers[i])->data
       );
    }
)

CHEAT_TEST(binary_search_tree_iterative_search_returns_null_if_not_found,
    struct TreeNode *root = get_tree_with_children();

    cheat_assert(
       binary_search_tree_search(root, 5) == NULL
    );
)
