#ifndef STATIC_QUEUE_H 
#define STATIC_QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 10

typedef struct queue queue_t;

typedef struct node {
    int value;
} node_t;

/**
 * @brief Create a queue object.
 * 
 * @return A pointer to the heap allocated region.
 */
queue_t *create_queue(void);

/**
 * @brief Checks if the queue contains data.
 * 
 * @param queue Object to be verified.
 * @return true if the queue is empty, false otherwise.
 */
bool is_empty(queue_t *queue);

/**
 * @brief Checks if the queue is full.
 * 
 * @param queue Object to be verified.
 * @return true if the queue is full, false otherwise.
 */
bool is_full(queue_t *queue);

/**
 * @brief Insert new data in the queue.
 * 
 * @param queue Pointer to handle the object.
 * @param data Node to be inserted into the queue.
 */
void queue_insert(queue_t *queue, node_t data);

/**
 * @brief Removes first data from queue.
 * 
 * @param queue Pointer to the queue object.
 */
void queue_remove(queue_t *queue);

/**
 * @brief Deallocate the queue memory.
 * 
 * @param queue double pointer to handle the object.
 */
void free_queue(queue_t **queue);

#endif