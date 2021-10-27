#include <stdlib.h>
#include "stack.h"

struct Stack** Stack_create() {
    struct Stack** stack = (struct Stack**) malloc(sizeof(struct Stack*));
    *stack = NULL;

    return stack;
}

struct Stack* Stack_create_node(int data) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->data = data;
    stack->next = NULL;

    return stack;
}

void Stack_push(struct Stack** stackRef, int data) {
    // Create the node
    struct Stack* node = Stack_create_node(data);

    // Save current stack top as next
    node->next = *stackRef;

    // Place the new node as stack top
    *stackRef = node;
}

void Stack_destroy_node(struct Stack** node) {
    (*node)->next = NULL;

    free(*node);
}

int Stack_pop(struct Stack** stackRef) {
    // Keep reference to the second item
    struct Stack *node = (*stackRef)->next;

    // Keep the node value to return it
    int data = (*stackRef)->data;

    // Save reference to top and destroy it
    struct Stack *top = *stackRef;
    Stack_destroy_node(&top);

    // Set second node as the new top
    (*stackRef) = node;

    // Return the popped value
    return data;
}