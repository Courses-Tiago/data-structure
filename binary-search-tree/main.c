#include <stdio.h>
#include <stdlib.h>
#include <binary_search_tree.h>

int main(void) {
    binary_search_tree_t *tree = NULL;
    tree_insert(&tree, 45);
    tree_insert(&tree, 18);
    tree_insert(&tree, 10);
    tree_insert(&tree, 50);
    tree_insert(&tree, 400);

    tree_order(tree);
    tree_remove(&tree, 18);
    tree_remove(&tree, 50);
    tree_order(tree);

    tree_remove(&tree, 400);
    tree_remove(&tree, 10);
    tree_remove(&tree, 45);
    return EXIT_SUCCESS;
}