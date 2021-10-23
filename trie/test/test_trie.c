#define CHEAT_NO_MATH

#include <stdbool.h>
#include <string.h>

#include "cheat.h"
#include "cheats.h"
#include "trie.h"

/**
 * Use case - insertion should work on empty trie
 *     root                             root
 *                                     /
 *                   insert("a")    a[0]
 *                  --------->
 */
CHEAT_TEST(trie_insertion_to_empty_trie,
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "a");

    cheat_assert(trie_search(root, "a") == true);
)

/**
 * Use case - insertion of multiple chars should work on empty trie
 *        root                         root
 *                                    /
 *                   insert("ab")  a[0]
 *                  --------->      \
 *                                   b[1]
 */
CHEAT_TEST(trie_multiple_char_insertion_to_empty_trie,
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "ab");

    cheat_assert(trie_search(root, "ab") == true);
)

/**
 * Use case - insertion of multiple chars should work on empty trie
 *        root                         root
 *                                    /
 *                   insert("abc")    a[0]
 *                  --------->        \
 *                                    b[1]
 *                                      \
 *                                      c[2]
 *
 *        root                            root
 *        /                           /          \
 *      a[0]       insert("cba")    a[0]        c[2]
 *        \          --------->       \          /
 *         b[1]                      b[1]      b[1]
 *           \                         \       /
 *           c[2]                      c[2]  a[0]
 */
CHEAT_TEST(trie_multiple_insertions,
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "abc");
    trie_insert(root, "cba");

    cheat_assert(trie_search(root, "abc") == true);
    cheat_assert(trie_search(root, "cba") == true);
)

/**
 * Use case - insertion sets up is_end_of_word correctly
 */
CHEAT_TEST(trie_insert_sets_end_of_word_correctly,
    struct TrieNode* root = trie_create_node();

    trie_insert(root, "hell");
    trie_insert(root, "hello");

    cheat_assert(trie_search(root, "hell") == true);
    cheat_assert(trie_search(root, "hello") == true);
    cheat_assert(trie_search(root, "hel") == false);
    cheat_assert(trie_search(root, "he") == false);
    cheat_assert(trie_search(root, "h") == false);
)

CHEAT_TEST(tree_is_node_empty_works_correctly,
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "aa");

    cheat_assert(trie_is_node_empty(root->children[0]) == false);
    cheat_assert(trie_is_node_empty(root->children[0]->children[0]) == true);
)