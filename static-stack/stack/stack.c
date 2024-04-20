#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

#define EMPTY_STACK -1

typedef struct stack {
    int *data;
    int capacity;
    int top;
} stack_t;

stack_t *create_stack(int capacity) {
    stack_t *stack = (stack_t *)malloc(1 * sizeof(stack_t));
    if(stack == NULL) {
        fprintf(stderr, "ERROR in 'create_stack'\n");
        fprintf(stderr, "Fail to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    if(capacity <= 0 || capacity > INT_MAX) {
        fprintf(stderr, "ERROR in 'create_stack'\n");
        fprintf(stderr, "Requested capacity out of bounds!\n");
        fprintf(stderr, 
        "Capacity must be greater than zero and less than or equal: %d\n", 
        INT_MAX);
        exit(EXIT_FAILURE);
    }
    stack->data = (int *)calloc((size_t)capacity, sizeof(int));
    if(stack->data == NULL) {
        fprintf(stderr, "ERROR in 'create_stack'\n");
        fprintf(stderr, "Fail to allocate memory to data pointer!\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

bool is_empty(const stack_t *stack) {
    return stack->top == EMPTY_STACK;
}

bool is_full(const stack_t *stack) {
    return stack->top == (stack->capacity - 1);
}

void push(stack_t *stack, int data) {
    if(is_full(stack)) {
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "Stack is Full!\n");
        free_stack(&stack);
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->data[stack->top] = data; 
}

void pop(stack_t *stack) {
    if(is_empty(stack)) {
        fprintf(stderr, "ERROR in 'pop'\n");
        fprintf(stderr, "Stack is Empty!\n");
        free_stack(&stack);
        exit(EXIT_FAILURE);
    }
    printf("Removed value: %d\n", stack->data[stack->top]);
    stack->top--;
}

void print_stack(const stack_t *stack) {
    if(is_empty(stack)) {
        printf("Empty stack\n");
        return;
    }
    for(int i = 0; i <= stack->top; i++) {
        printf("Stack[%d]: %d\n", i, stack->data[i]);
    }
}

void free_stack(stack_t **stack) {
    free((*stack)->data);
    (*stack)->data = NULL;
    free(*stack);
    *stack = NULL;
}