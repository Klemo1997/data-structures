#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_
#include <stdlib.h>

#define DEFAULT_SIZE 2
#define MAX_STR_LENGTH 64

/**
 * Node base structure
 */
struct ArrayList {
    // Reference to string array
    char** str_array;

    // Current length of arraylist
    int length;

    // Current allocated size of arraylist
    int size;
};

/**
 * Creates and initializes an empty arraylist
 * of DEFAULT_SIZE size
 */
struct ArrayList* array_list_create();

/**
 * Destroys arraylist and frees associated memory
 */
void array_list_destroy(struct ArrayList** array_list);

/**
 * Inserts given string to the end of arraylist
 */
void array_list_insert(struct ArrayList** arrayListRef, const char* str);

/**
 * Retrieves string saved on given index in arraylist
 */
char* array_list_at(struct ArrayList* arrayList, int index);

/**
 * Creates an array of strings with minimal size from arraylist
 */
char** array_list_get_minimal_array(struct ArrayList* arrayList);

#endif _ARRAY_LIST_H_