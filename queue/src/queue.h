#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

struct Queue {
    /**
     * Front and rear queue index holders
     */
    int front, rear;

    /**
     * Queue current size
     */
    int size;

    /**
     * Queue max capacity
     */
    unsigned capacity;

    /**
     * Queue data
     */
    int* data;
};

struct Queue* Queue_create(unsigned capacity);

void Queue_enqueue(struct Queue** queue, int data);

int Queue_dequeue(struct Queue** queue);

int Queue_front(struct Queue* queue);

int Queue_rear(struct Queue* queue);

bool Queue_isEmpty(struct Queue* queue);

#endif _QUEUE_H_