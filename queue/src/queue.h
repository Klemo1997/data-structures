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

/**
 * Create queue with given capacity
 */
struct Queue* Queue_create(unsigned capacity);

/**
 * Enqueue item in queue
 */
void Queue_enqueue(struct Queue** queue, int data);

/**
 * Dequeue item from queue
 */
int Queue_dequeue(struct Queue** queue);

/**
 * Get queue front (first item to be dequeued)
 */
int Queue_front(struct Queue* queue);

/**
 * Get queue rear (most recent item enqueued)
 */
int Queue_rear(struct Queue* queue);

/**
 * Find whether the queue is empty or not
 */
bool Queue_isEmpty(struct Queue* queue);

#endif _QUEUE_H_