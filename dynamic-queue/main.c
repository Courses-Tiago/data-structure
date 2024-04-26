#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

int main(void) {
    queue_t *queue = create_queue();
    init_queue(&queue);
    queue_insert(queue, 'X');
    queue_insert(queue, 'V');
    queue_insert(queue, 'A');
    peek(queue);
    queue_remove(queue);
    queue_remove(queue);
    queue_remove(queue);

    queue_insert(queue, 'S');
    queue_insert(queue, 'P');
    queue_insert(queue, 'F');
    queue_insert(queue, 'C');

    destroy_queue(&queue);
    return EXIT_SUCCESS;
}