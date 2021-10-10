#include <stdio.h>

#include "linked_list.h"


int main() {
    struct Node* head = NULL;
    linked_list_append(&head, 2);
    linked_list_prepend(&head, 1);
    linked_list_print(head);
    linked_list_destroy(&head);

    return 0;
}
