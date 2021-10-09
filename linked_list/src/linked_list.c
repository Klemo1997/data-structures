#include <stdlib.h>
#include "linked_list.h"

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