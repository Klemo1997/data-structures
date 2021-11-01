#include <stdlib.h>
#include <limits.h>
#include "queue.h"

struct Queue* Queue_create(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    // Initialize queue properties to zero
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;

    // Set queue capacity
    queue->capacity = capacity;

    // Allocate an array with given capacity
    queue->data = (int*) malloc(capacity * sizeof(int));

    return queue;
}

void Queue_destroy(struct Queue** queue) {
    free((*queue)->data);
    (*queue)->data = NULL;

    free(*queue);

    *queue = NULL;
}

bool Queue_isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void Queue_enqueue(struct Queue** queue, int data) {
    // The queue is full, let it overflow
    if ((*queue)->size == (*queue)->capacity) {
        return;
    }

    int offset = (*queue)->size % (*queue)->capacity;

    (*queue)->data[offset] = data;

    // Increase rear index
    (*queue)->rear = offset;

    // Increase size
    (*queue)->size++;
}

int Queue_dequeue(struct Queue** queue) {
    if (Queue_isEmpty(*queue)) {
        return INT_MIN;
    }

    int front_data = Queue_front(*queue);

    // Increase front index
    (*queue)->front = ((*queue)->front + 1) % (int) (*queue)->capacity;

    // Decrease queue size
    (*queue)->size--;

    return front_data;
}

int Queue_front(struct Queue* queue) {
    if (Queue_isEmpty(queue)) {
        return INT_MIN;
    }

    return queue->data[queue->front];
}

int Queue_rear(struct Queue* queue) {
    if (Queue_isEmpty(queue)) {
        return INT_MIN;
    }

    return queue->data[queue->rear];
}