#include <stdlib.h>
#include <string.h>
#include "array_list.h"

char** array_list_create_str_array(int size) {
    char** strArray = (char**) malloc(size * sizeof(char*));

    for (int i = 0; i < size; i++) {
        strArray[i] = (char*) malloc(MAX_STR_LENGTH * sizeof(char));
    }

    return strArray;
}

/**
 * Frees string array
 */
void array_list_destroy_str_array(char** strArray, int size) {
    for (int i = 0; i < size; i++) {
        free(strArray[i]);
    }

    free(strArray);
}

struct ArrayList* array_list_create() {
    struct ArrayList* arrayList = (struct ArrayList*) malloc(sizeof(struct ArrayList));

    arrayList->length = 0;
    arrayList->size = DEFAULT_SIZE;
    arrayList->str_array = array_list_create_str_array(DEFAULT_SIZE);

    return arrayList;
}

void array_list_destroy(struct ArrayList** array_list) {
    // Clean allocated memory for strings
    array_list_destroy_str_array((*array_list)->str_array, (*array_list)->size);

    // Clean allocated memory for array list structure
    free(*array_list);

    *array_list = NULL;
}

/**
 * Doubles the size of arraylist and copies its contents
 * into new array of strings
 */
void array_list_extend(struct ArrayList** arrayListRef) {
    int new_size = (*arrayListRef)->size * 2;

    char** old_str_array = (*arrayListRef)->str_array;
    char** new_str_array = array_list_create_str_array(new_size);

    for (int i = 0; i < (*arrayListRef)->length; i++) {
        strcpy(new_str_array[i], old_str_array[i]);
    }

    array_list_destroy_str_array(old_str_array, (*arrayListRef)->size);

    (*arrayListRef)->str_array = new_str_array;
    (*arrayListRef)->size = new_size;
}

void array_list_insert(struct ArrayList** arrayListRef, const char* str) {
    if ((*arrayListRef)->length == (*arrayListRef)->size) {
        array_list_extend(arrayListRef);
    }

    strcpy((*arrayListRef)->str_array[(*arrayListRef)->length++], str);
}

char* array_list_at(struct ArrayList* arrayList, const int index) {
    return arrayList->str_array[index];
}

char** array_list_get_minimal_array(struct ArrayList* arrayList) {
    char** minimal_array = (char**) malloc(arrayList->length * sizeof(char*));

    for (int i = 0; i < arrayList->length; i++) {
        minimal_array[i] = (char*) malloc((strlen(arrayList->str_array[i]) + 1) * sizeof(char));
        strcpy(minimal_array[i], arrayList->str_array[i]);
    }

    minimal_array[arrayList->length] = NULL;

    return minimal_array;
}