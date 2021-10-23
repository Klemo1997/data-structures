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

bool trie_search(struct TrieNode* root, const char* key) {
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

bool trie_is_node_empty(struct TrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            return false;
        }
    }

    return true;
}

void trie_delete_recursive(struct TrieNode** root, const char *key, const int depth) {
    if (*root == NULL) {
        return;
    }

    if (depth == strlen(key)) {
        (*root)->is_end_of_word = false;

        if (trie_is_node_empty(*root)) {
            free(*root);
            *root = NULL;
        }

        return;
    }

    int char_index = CHAR_TO_INDEX(key[depth]);

    trie_delete_recursive(&(*root)->children[char_index], key, depth + 1);

    if (
        // If node is not a root
        depth > 0
        // And has no children
        && trie_is_node_empty(*root)
        // And neither is an end of word
        && !(*root)->is_end_of_word
    ) {
        // We can deallocate the node
        free(*root);
        *root = NULL;
    }
}

void trie_delete(struct TrieNode **root, const char *key) {
    trie_delete_recursive(root, key, 0);
}