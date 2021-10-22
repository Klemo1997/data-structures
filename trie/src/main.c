#include "trie.h"

int main() {
    struct TrieNode* root = trie_create_node();
    trie_insert(root, "abc");
    trie_insert(root, "cba");
    return 0;
}
