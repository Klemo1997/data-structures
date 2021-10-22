#include <stdlib.h>
#include <string.h>
#include "trie.h"

struct TrieNode* trie_create_node(void) {
    struct TrieNode* root = (struct TrieNode*) malloc(sizeof(struct TrieNode));

    if (!root) {
        return NULL;
    }

    root->is_end_of_word = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        root->children[i] = NULL;
    }

    return root;
}

void trie_insert(struct TrieNode *root, const char *key) {
    struct TrieNode* temp = root;

    for (int i = 0; i < strlen(key); i ++) {
        int char_index = CHAR_TO_INDEX(key[i]);

        // We crawl through the trie
        // and initialize nodes as we go
        if (!temp->children[char_index]) {
            temp->children[char_index] = trie_create_node();
        }

        temp = temp->children[char_index];
    }

    // When we get to right node, we initialize it as the end of word
    temp->is_end_of_word = true;
}