#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

node_t create_node(int value);

int main(void) {
    queue_t *queue = create_queue();
    node_t n[QUEUE_SIZE];
    for(int i = 0; i < QUEUE_SIZE; i++) {
        n[i] = create_node(i * 5);
        queue_insert(queue, n[i]);
    }
    for(int i = 0; i < QUEUE_SIZE; i++) {
        queue_remove(queue);
    }
    free_queue(&queue);
    return EXIT_SUCCESS;
}

node_t create_node(int value) {
    node_t new = {
        value,
    };
    return new;
}