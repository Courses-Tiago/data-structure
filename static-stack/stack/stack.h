#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack stack_t;

/**
 * @brief Creates a stack object.
 * 
 * @param capacity desired size to the stack.
 * @return stack_t* pointer containing heap address.
 */
stack_t *create_stack(int capacity);

/**
 * @brief Checks if the stack is empty.
 * 
 * @param stack Object to be verified.
 * @return true if stack is empty, false otherwise.
 */
bool is_empty(const stack_t *stack);

/**
 * @brief Checks if the stack is full.
 * 
 * @param stack Object to be verified.
 * @return true if stack is full, false otherwise.
 */
bool is_full(const stack_t *stack);

/**
 * @brief Inserts data in the stack.
 * 
 * @param stack Object to insert data.
 * @param data Value to insert in the stack.
 */
void push(stack_t *stack, int data);

/**
 * @brief Removes the last inserted data.
 * 
 * @param stack Object to remove the data.
 */
void pop(stack_t *stack);

/**
 * @brief Prints the stack content.
 * 
 * @param stack Object to print the contained data.
 */
void print_stack(const stack_t *stack);

/**
 * @brief Deallocates stack's memory.
 * 
 * @param stack Object to deallocate heap memory.
 */
void free_stack(stack_t *stack);

#endif