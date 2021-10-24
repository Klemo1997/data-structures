#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdbool.h>

#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

/**
 * Node base structure
 */
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];

    // True if the node represents end of a word
    bool is_end_of_word;
};

/**
 * Create node and initialize its children with NULL values
 */
struct TrieNode* trie_create_node(void);

/**
 * Insert a key into trie
 */
void trie_insert(struct TrieNode *root, const char *key);

/**
 * Find if given key is present in trie or not
 */
bool trie_search(struct TrieNode *root, const char *key);

/**
 * Checks if node has some allocated children
 */
bool trie_is_node_empty(struct TrieNode *root);

/**
 * Delete given key from trie if it exists
 */
void trie_delete(struct TrieNode **root, const char *key);

/**
 * Get the longest common prefix matching given key
 *
 * Example: if dictionary contains keys: {a, are, xyz}
 * and key "arebcd" is provided, it should return "are"
 */
const char* trie_get_longest_prefix(struct TrieNode* root, const char *key);

/**
 * Get all auto suggestions (descendants) of given key
 */
char** trie_get_autocomplete_suggestions(struct TrieNode* root, const char *key);

#endif _TRIE_H_