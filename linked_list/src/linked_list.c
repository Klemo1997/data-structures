#include <stdlib.h>
#include "linked_list.h"

struct Node* linked_list_create_node(int value) {
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->data = value;

    return newNode;
}
