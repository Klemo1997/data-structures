#include <stdio.h>
#include "trie.h"

int main() {
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "a");
    trie_insert(root, "app");
    trie_insert(root, "apple");
    trie_insert(root, "appleton");

    char** array = trie_get_autocomplete_suggestions(root, "ap");

    for(int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}
