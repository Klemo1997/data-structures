#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/**
 * Node base structure
 */
struct Node {
    int data;
    struct Node* next;
};

/**
 * Allocate new node with given value
 */
struct Node* linked_list_create_node(int value);

/**
 * Print values in linked list
 */
void linked_list_print(struct Node* head);

/**
 * Prepend item as the new head of linked list
 */
void linked_list_prepend(struct Node** head, int data);

/**
 * Append item at the end of linked list
 */
void linked_list_append(struct Node** head, int data);

/**
 * Delete first match of item from linked list
 */
void linked_list_delete(struct Node** head, int data);

/**
 * Destroy whole linked list and free its memory
 */
void linked_list_destroy(struct Node** head);

#endif _LINKED_LIST_H_