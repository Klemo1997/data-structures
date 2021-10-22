#define CHEAT_NO_MATH

#include <stdbool.h>
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

    cheat_assert(root->children[0] != NULL);
    cheat_assert(root->children[0]->is_end_of_word == true);
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

    cheat_assert(root->children[0] != NULL);
    cheat_assert(root->children[0]->is_end_of_word == false);
    cheat_assert(root->children[0]->children[1] != NULL);
    cheat_assert(root->children[0]->children[1]->is_end_of_word == true);
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
 */
CHEAT_TEST(trie_multiple_insertions,
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "abc");
    trie_insert(root, "cba");

    // First word
    cheat_assert(root->children[0] != NULL);
    cheat_assert(root->children[0]->is_end_of_word == false);
    cheat_assert(root->children[0]->children[1] != NULL);
    cheat_assert(root->children[0]->children[1]->is_end_of_word == false);
    cheat_assert(root->children[0]->children[1]->children[2] != NULL);
    cheat_assert(root->children[0]->children[1]->children[2]->is_end_of_word == true);

    // Second word
    cheat_assert(root->children[2] != NULL);
    cheat_assert(root->children[2]->is_end_of_word == false);
    cheat_assert(root->children[2]->children[1] != NULL);
    cheat_assert(root->children[2]->children[1]->is_end_of_word == false);
    cheat_assert(root->children[2]->children[1]->children[0] != NULL);
    cheat_assert(root->children[2]->children[1]->children[0]->is_end_of_word == true);
)