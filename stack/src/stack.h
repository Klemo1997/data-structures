#ifndef _STACK_H_
#define _STACK_H_

/**
 * Stack structure
 */
struct Stack {
    int data;

    struct Stack* next;
};

struct Stack** Stack_create();

void Stack_push(struct Stack** stack, int data);

int Stack_pop(struct Stack** stack);

#endif _STACK_H_