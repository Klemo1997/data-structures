#define CHEAT_NO_MATH

#include <stdbool.h>
#include <string.h>

#include "cheat.h"
#include "cheats.h"
#include "trie.h"

CHEAT_DECLARE(
    void assert_trie_contains(struct TrieNode* root, const char* key) {
        struct TrieNode* temp = root;
        int char_index;

        for (int i = 0; i < strlen(key); i++) {
            cheat_assert(temp != NULL);
            //todo: This applies only on non-crossing words in tries
            cheat_assert(temp->is_end_of_word == false);

            char_index = CHAR_TO_INDEX(key[i]);
            temp = temp->children[char_index];
        }

        cheat_assert(temp != NULL);
        cheat_assert(temp->is_end_of_word == true);
    }
)

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

    assert_trie_contains(root, "a");
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

    assert_trie_contains(root, "ab");
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

    assert_trie_contains(root, "abc");
    assert_trie_contains(root, "cba");
)