#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node {
    char info;
    struct node *next;
} node_t;

typedef struct queue {
    int size;
    node_t *start;
    node_t *end;
} queue_t;

queue_t *create_queue(void) {
    queue_t *new = (queue_t*)malloc(1 * sizeof(queue_t));
    if(new == NULL) {
        fprintf(stderr, "ERROR in 'create_queue'\n");
        fprintf(stderr, "Fail to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    return new;
}

void init_queue(queue_t **queue) {
    (*queue)->size = 0;
    (*queue)->start = NULL;
    (*queue)->end = NULL;
}

bool is_empty(queue_t *queue) {
    return (queue->size == 0);
}

void peek(const queue_t *queue) {
    printf("First data: %c\n", queue->start->info);
}

void queue_insert(queue_t *queue, char data) {
    node_t *new = (node_t*)malloc(1 * sizeof(node_t));
    if(new == NULL) {
        printf("Fail to allocate a new node\n");
        return;
    }
    new->info = data;
    new->next  = NULL;
    if(is_empty(queue)) {
        queue->start = queue->end = new;
    }
    else {
        queue->end->next = new;
        queue->end = new;
    }
    queue->size++;
}

void queue_remove(queue_t *queue) {
    if(is_empty(queue)) {
        printf("Error, the queue is empty!\n");
        return;
    }
    node_t *aux = queue->start;
    queue->start = aux->next;
    queue->size--;
    if(is_empty(queue));
        queue->end = NULL;
    
    printf("Removed item: %c\n", aux->info);
    free(aux);
}

void destroy_queue(queue_t **queue) {
    if((*queue)->start == NULL) {
        printf("No memory to deallocate\n");
        return;
    }
    node_t *aux = NULL;
    while((*queue)->start) {
        aux = (*queue)->start;
        (*queue)->start = aux->next;
        printf("Freed: %c\n", aux->info);
        free(aux);
    }
    (*queue)->end = NULL;
    free(*queue);
    *queue = NULL;
}