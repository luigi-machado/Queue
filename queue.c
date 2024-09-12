#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"


void queue_init(queue_t *q) {
    q->max_size = 50;
    q->array = malloc(q->max_size * sizeof(item));
    q->size = 0;
}


void queue_destroy(queue_t *q) {
    free(q->array);
    q->size = 0;
}


bool queue_empty(queue_t *q) {
    if (q->size == 0)
        return true;
    return false;
}


bool queue_full(queue_t *q) {
    if (q->size == q->max_size) 
        return true;
    return false;
}


bool enqueue(item i, queue_t *q) {
    if (queue_empty(q)) {
        q->array[0] = i;
        q->first = 0;
        q->last = 0;
        return true;
    }
    if (queue_full(q)){
        q->max_size *= 2;
        q->array = realloc(q->array, q->max_size);
        if (q->array == NULL) {
            return false;
        }
    }
    q->last = (q->last + 1) % q->max_size;
    q->array[q->last] = i;
    q->size++;
    return true;
}


bool dequeue(queue_t *q, item *i) {
    if (queue_empty(q)) {
        return false;
    }
    *i = q->array[q->first];
    q->first = (q->first + 1) % q->max_size;
    q->size--;
    return true;
}


void queue_print(queue_t *q) {
    printf("[ ");
    for (int i = q->first; i < q->size; i++) {
        printf("%d ", q->array[i]);
    }
    printf("]");
}


item queue_peek(queue_t *q) {
    return q->array[q->first];
}
