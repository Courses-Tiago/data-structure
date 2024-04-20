#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main(void) {
    stack_t *stack = create_stack(10);
    push(stack, 45);
    push(stack, 88);
    push(stack, 34);
    print_stack(stack);
    free_stack(&stack);
    return EXIT_SUCCESS;
}