#define CHEAT_NO_MATH

#include <stdbool.h>
#include <string.h>

#include "cheat.h"
#include "cheats.h"
#include "trie.h"

CHEAT_DECLARE(
    bool does_trie_contain_key(struct TrieNode* root, const char* key) {
        struct TrieNode* temp = root;
        int char_index;

        for (int i = 0; i < strlen(key); i++) {
            if (temp == NULL) {
                return false;
            }

            char_index = CHAR_TO_INDEX(key[i]);
            temp = temp->children[char_index];
        }

        return temp->is_end_of_word;
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

    cheat_assert(does_trie_contain_key(root, "a") == true);
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

    cheat_assert(does_trie_contain_key(root, "ab") == true);
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

    cheat_assert(does_trie_contain_key(root, "abc") == true);
    cheat_assert(does_trie_contain_key(root, "cba") == true);
    does_trie_contain_key(root, "cba");
)

/**
 * Use case - insertion sets up is_end_of_word correctly
 */
CHEAT_TEST(trie_insert_sets_end_of_word_correctly,
    struct TrieNode* root = trie_create_node();

    trie_insert(root, "hell");
    trie_insert(root, "hello");

    cheat_assert(does_trie_contain_key(root, "hell") == true);
    cheat_assert(does_trie_contain_key(root, "hello") == true);
    cheat_assert(does_trie_contain_key(root, "hel") == false);
    cheat_assert(does_trie_contain_key(root, "he") == false);
    cheat_assert(does_trie_contain_key(root, "h") == false);
)