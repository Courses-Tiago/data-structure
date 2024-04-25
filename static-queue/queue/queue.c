#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct queue {
    node_t data[QUEUE_SIZE];
    int size;
    int start;
    int end;  
} queue_t;

queue_t *create_queue(void) {
    queue_t *queue = (queue_t*)malloc(1 * sizeof(queue_t));
    if(queue == NULL) {
        fprintf(stderr, "ERROR in 'create_queue'\n");
        fprintf(stderr, "Fail to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    queue->end = -1;
    queue->start = 0;
    queue->size = 0;
    return queue;
}

bool is_empty(queue_t *queue) {
    return (queue->size == 0);
}

bool is_full(queue_t *queue) {
    return (queue->size == QUEUE_SIZE);
}

void queue_insert(queue_t *queue, node_t data) {
    if(is_full(queue)) {
        printf("Error, the queue is full!\n");
        return;
    }
    queue->size++;
    queue->end = (queue->end + 1) % QUEUE_SIZE;
    queue->data[queue->end] = data;
}

void queue_remove(queue_t *queue) {
    if(is_empty(queue)) {
        printf("Error, the queue is empty!\n");
        return;
    }
    queue->size--;
    printf("Removed data: %d\n", queue->data[queue->start].value);
    queue->start = (queue->start + 1) % QUEUE_SIZE;
}

void free_queue(queue_t **queue) {
    free(*queue);
    *queue = NULL;
}