#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define PRINT_SEPARATOR ", "

struct Node* linked_list_create_node(int value) {
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = value;

    return newNode;
}

void linked_list_prepend(struct Node** linked_list, int data) {
    if (*linked_list == NULL) {
        *linked_list = linked_list_create_node(data);
        return;
    }

    // Keep reference to current head
    struct Node* oldHeadRef = *linked_list;

    // Assign new head
    *linked_list = linked_list_create_node(data);

    // Add old head as next node
    (*linked_list)->next = oldHeadRef;
}

/**
 * Get last element of linked list
 *
 * @internal
 */
struct Node** linked_list_get_last_element(struct Node** linked_list) {
    if (linked_list == NULL) {
        return NULL;
    }

    struct Node** current_element = linked_list;

    while ((*current_element)->next != NULL) {
        *current_element = (*current_element)->next;
    }

    return current_element;
}

void linked_list_append(struct Node** linked_list, int data) {
    if (*linked_list == NULL) {
        *linked_list = linked_list_create_node(data);
        return;
    }

    struct Node** last_element = linked_list_get_last_element(linked_list);

    (*last_element)->next = linked_list_create_node(data);
}

void linked_list_print(struct Node* head) {
    struct Node* current_element = head;

    while (current_element != NULL) {
        printf("%d", current_element->data);
        current_element = current_element->next;

        if (current_element != NULL) {
            printf(PRINT_SEPARATOR);
        }
    }
}