#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef int item;

typedef struct queue_t {
    item* array;
    int max_size;
    int size;
    int first;
    int last;
} queue_t;

// Allocs memory and makes the queue ready for use
void queue_init(queue_t *q);

// Frees the allocated memory
void queue_destroy(queue_t *q);

bool queue_empty(queue_t *q);

bool queue_full(queue_t *q);

bool enqueue(item i, queue_t *q);

bool dequeue(queue_t *q, item *i);

// Prints the queue elements
void queue_print(queue_t *q);

item queue_peek(queue_t *q);


#endif
