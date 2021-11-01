#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <string.h>

/**
 * Hash table element
 */
struct HashTableEntry {
    /**
     * Key and value pointers references
     */
    void* key;
    void* value;

    /**
     * Hash result
     */
    unsigned int hash;

    /**
     * Reference to next element in case there is collision
     */
    struct HashTableEntry* next;
};

struct HashTable {
    /**
     * Table length
     */
    unsigned int length;

    /**
     * Table entries
     */
    struct HashTableEntry** entries;

    /**
     * Number of entries
     */
    unsigned int entry_count;

    /**
     * Load limit of table
     */
    unsigned int load_limit;

    /**
     * Prime index
     */
    unsigned int prime_index;

    /**
     * Hash function reference
     */
    unsigned int (*hash_fn) (void *k);

    /**
     * Compare function for keys
     */
    int (*eq_fn) (void *k1, void *k2);
};

/**
 * Create hash table instance
 *
 * @param min_size minimal initial size of table
 * @param hash_fn key hashing function
 * @param eq_fn compare function for keys
 * @return
 */
struct HashTable* HashTable_create(
    unsigned int min_size,
    unsigned int (*hash_fn) (void*),
    int (*eq_fn) (void*, void*)
);

/**
 * Insert given key - value entry into hashtable
 *
 * @param hash_table
 * @param key
 * @param value
 * @return non-zero value if insertion was successful
 */
int HashTable_insert(
    struct HashTable* hash_table,
    void* key,
    void* value
);

/**
 * Search for value associated with given key in hash table
 *
 * @param hash_table
 * @param key
 *
 * @return associated value, if exists, NULL otherwise
 */
void* HashTable_search(
    struct HashTable* hash_table,
    void* key
);

/**
 * Delete entry with given key if exists and return it
 *
 * @param hash_table
 * @param key
 *
 * @return associated value, if exists, NULL otherwise
 */
void* HashTable_remove(
    struct HashTable* hash_table,
    void* key
);

/**
 * Deallocate hash table
 *
 * @param hash_table
 */
void HashTable_destroy(struct HashTable* hash_table);

#endif _HASH_TABLE_H_