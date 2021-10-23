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

CHEAT_TEST(trie_is_node_empty_works_correctly,
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "aa");

    cheat_assert(trie_is_node_empty(root->children[0]) == false);
    cheat_assert(trie_is_node_empty(root->children[0]->children[0]) == true);
)

/**
 * Use case - delete the only word that trie contains
 * Also check if children are pointed to NULL after deallocation
 */
CHEAT_TEST(trie_delete_single_word,
   struct TrieNode* root = trie_create_node();
   trie_insert(root, "aa");
   trie_delete(&root, "aa");

   cheat_assert(trie_search(root, "aa") == false);
   cheat_assert(root->children[0] == NULL);
)

/**
 * Use case - Delete all inserted words in chronological order
 */
CHEAT_TEST(trie_delete_multiple_words,
    struct TrieNode* root = trie_create_node();

    trie_insert(root, "aha");
    trie_insert(root, "hello");

    trie_delete(&root, "aha");
    trie_delete(&root, "hello");

    cheat_assert(!trie_search(root, "aha"));
    cheat_assert(!trie_search(root, "hello"));
)

/**
 * Use case - Trie preserves non deleted words
 */
CHEAT_TEST(trie_preserves_non_deleted_words,
    struct TrieNode* root = trie_create_node();

    trie_insert(root, "aha");
    trie_insert(root, "hello");

    trie_delete(&root, "aha");

    cheat_assert(!trie_search(root, "aha"));
    cheat_assert(trie_search(root, "hello"));
)

/**
 * Use case - Trie preserves shared path:
 * words test and testing has shared path in t-e-s-t
 *
 * We have to ensure that deleting [test] key does not affect path
 * to [testing] key
 */
CHEAT_TEST(trie_delete_preserves_shared_path,
    struct TrieNode* root = trie_create_node();

    trie_insert(root, "test");
    trie_insert(root, "testing");

    trie_delete(&root, "test");

    cheat_assert(!trie_search(root, "test"));
    cheat_assert(trie_search(root, "testing"));
)

/**
 * Use case - Trie preserves shared path when longer word is deleted:
 * words test and testing has shared path in t-e-s-t
 *
 * We have to ensure that deleting [testing] key does not affect path
 * to shorter [test] key
 */
CHEAT_TEST(trie_delete_preserves_shared_path_when_longer_word_is_deleted,
    struct TrieNode* root = trie_create_node();

    trie_insert(root, "test");
    trie_insert(root, "testing");

    trie_delete(&root, "testing");

    cheat_assert(trie_search(root, "test"));
    cheat_assert(!trie_search(root, "testing"));
)