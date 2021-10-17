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

/**
 * Use case - insertion should work on empty tree
 *              NULL                             2
 *                           insert(2)
 *                          --------->
 */
CHEAT_TEST(binary_search_tree_insertion_to_empty_tree,
    struct TreeNode *root = get_single_node_tree();

    cheat_assert_int(root->data, 2);
)

/**
 * Use case - insertion should respect BST order rule
 *              NULL                             2
 *                           insert(2)
 *                          --------->
 *              2                                2
 *                          insert(1)           /
 *                         ---------->         1
 *
 *              2                                2
 *             /            insert(3)           / \
 *            1            ---------->         1   3
 */
CHEAT_TEST(binary_search_tree_insertion_multiple_inserts,
    struct TreeNode *root = get_tree_with_children();

    cheat_assert_int(root->data, 2);
    cheat_assert_int(root->left->data, 1);
    cheat_assert_int(root->right->data, 3);
)

/**
 * Use case - insertion should prevent adding duplicates
 *              NULL                             2
 *                           insert(2)
 *                          --------->
 *              2                                2
 *                          insert(2)
 *                         ---------->
 *
 */
CHEAT_TEST(binary_search_tree_insertion_does_not_add_duplicates,
    struct TreeNode *root = NULL;
    binary_search_tree_insert(&root, 2);
    binary_search_tree_insert(&root, 2);

    cheat_assert_int(root->data, 2);
    cheat_assert(root->left == NULL);
    cheat_assert(root->right == NULL);
)

/**
 * Use case - search for root
 */
CHEAT_TEST(binary_search_tree_search_finds_root,
    struct TreeNode *root = NULL;
    binary_search_tree_insert(&root, 2);

    cheat_assert_int(
       2,
       binary_search_tree_search(root, 2)->data
    );
)

/**
 * Use case - deeper search
 */
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

/**
 * Use case - searching for non existing node
 */
CHEAT_TEST(binary_search_tree_search_returns_null_if_not_found,
    struct TreeNode *root = get_tree_with_children();

    cheat_assert(
       binary_search_tree_search(root, 5) == NULL
    );
)

/**
 * Use case - search for root with iterative method
 */
CHEAT_TEST(binary_search_tree_iterative_search_finds_root,
   struct TreeNode *root = NULL;
   binary_search_tree_insert(&root, 2);

   cheat_assert_int(
       2,
       binary_search_tree_iterative_search(root, 2)->data
   );
)

/**
 * Use case - search with iterative method
 */
CHEAT_TEST(binary_search_tree_iterative_search_finds_iteratively,
    struct TreeNode *root = get_tree_with_children();
    int numbers[3] = {2,1,3};

    for (int i = 0; i < 3; i++) {
       cheat_assert_int(
           numbers[i],
           binary_search_tree_iterative_search(root, numbers[i])->data
       );
    }
)

/**
 * Use case - searching for non existing node with iterative method
 */
CHEAT_TEST(binary_search_tree_iterative_search_returns_null_if_not_found,
    struct TreeNode *root = get_tree_with_children();

    cheat_assert(
       binary_search_tree_iterative_search(root, 5) == NULL
    );
)

/**
 * Use case - empty tree
 *     NULL                 NULL
 *             delete(2)
 *            --------->
 */
CHEAT_TEST(binary_search_tree_delete_does_nothing_with_empty_tree,
    struct TreeNode *root = NULL;
    binary_search_tree_delete(&root, 2);

    cheat_assert(root == NULL);
)

/**
 * Use case - single node tree
 *     2                             NULL
 *                 delete(2)
 *                --------->
 */
CHEAT_TEST(binary_search_tree_deletes_single_node,
    struct TreeNode *root = get_single_node_tree();
    binary_search_tree_delete(&root, 2);

    cheat_assert(root == NULL);
)


CHEAT_DECLARE(
    int convert_tree_to_array(struct TreeNode *node, int arr[], int i) {
        if(node == NULL)
            return i;


        arr[i] = node->data;
        i++;
        if(node->left != NULL)
            i = convert_tree_to_array(node->left, arr, i);
        if(node->right != NULL)
            i = convert_tree_to_array(node->right, arr, i);

        return i;
    }

    int is_tree_the_same(struct TreeNode* root, const int* expected_array, int elements_count) {
        int* tree_array = (int*) malloc (elements_count * sizeof(int));
        convert_tree_to_array(root, tree_array, 0);

        for (int i = 0; i < elements_count; i ++) {
            if (tree_array[i] != expected_array[i]) {
                return 0;
            }
        }

        return 1;
    }
)

/**
 * Use case - node is a leaf
 *              50                             50
 *             /   \         delete(20)      /   \
 *          30      70       --------->    30     70
 *         /  \    /  \                     \    /  \
 *       20   40  60   80                   40  60   80
 */
CHEAT_TEST(binary_search_tree_deletes_only_list_node,
    int initial_tree[7] = {50, 30, 20, 40, 70, 60, 80};
    int output_tree[6] = {50, 30, 40, 70, 60, 80};

    struct TreeNode* root = NULL;

    construct_binary_search_tree(&root, initial_tree, 7);

    binary_search_tree_delete(&root, 20);

    cheat_assert(is_tree_the_same(root, output_tree, 6));
)

/**
 * Use case - node has only right child
 *               50                            50
 *             /   \         delete(30)      /   \
 *          30      70       --------->    40     70
 *            \    /  \                          /  \
 *            40  60   80                       60   80
 */
CHEAT_TEST(binary_search_tree_deletes_and_references_its_child,
   int initial_tree[6] = {50, 30, 40, 70, 60, 80};
   int output_tree[5] = {50, 40, 70, 60, 80};

   struct TreeNode* root = NULL;

   construct_binary_search_tree(&root, initial_tree, 6);

   binary_search_tree_delete(&root, 30);

   cheat_assert(is_tree_the_same(root, output_tree, 5));
)

/**
 * Use case - node has both children
 *               50                            60
 *             /   \         delete(50)      /   \
 *          40      70       --------->    40     70
 *                 /  \                             \
 *                60   80                            80
 */
CHEAT_TEST(binary_search_tree_deletes_and_uses_in_order_successor,
    int initial_tree[5] = {50, 40, 70, 60, 80};
    int output_tree[4] = {60, 40, 70, 80};

    struct TreeNode* root = NULL;

    construct_binary_search_tree(&root, initial_tree, 5);

    binary_search_tree_delete(&root, 50);

    cheat_assert(is_tree_the_same(root, output_tree, 4));
)