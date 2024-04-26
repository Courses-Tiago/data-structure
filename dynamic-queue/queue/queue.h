#ifndef STATIC_QUEUE_H 
#define STATIC_QUEUE_H

#include <stdbool.h>

typedef struct queue queue_t;
typedef struct node node_t;

/**
 * @brief Allocates a queue object on heap memory.
 * 
 * @return Memory region to queue object.
 */
queue_t *create_queue(void);

/**
 * @brief Initialize a queue object.
 * 
 * @param queue double pointer to handle a queue.
 */
void init_queue(queue_t **queue);

/**
 * @brief Checks if the queue contains data.
 * 
 * @param queue Object to be verified.
 * @return true if the queue is empty, false otherwise.
 */
bool is_empty(queue_t *queue);

/**
 * @brief Prints the first queue content.
 * 
 * @param queue Object to print the contained data.
 */
void peek(const queue_t *queue);

/**
 * @brief Insert new data in the queue.
 * 
 * @param queue Pointer to handle the object.
 * @param data value to be inserted into the queue.
 */
void queue_insert(queue_t *queue, char data);

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
void destroy_queue(queue_t **queue);

#endif