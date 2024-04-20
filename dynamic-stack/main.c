#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main(void) {
    stack_t *stack;
    init_stack(&stack);
    push(&stack, 57);
    push(&stack, 5);
    push(&stack, 321);
    push(&stack, 3);
    peek(stack);
    pop(&stack);
    free_all_stack(&stack);
    return EXIT_SUCCESS;
}