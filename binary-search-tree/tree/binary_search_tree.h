#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef struct binary_search_tree binary_search_tree_t;
typedef unsigned int u32;

typedef enum {
    ROOT = 0x0,
    LEAF,
    RIGHT_ONLY,
    LEFT_ONLY,
    SUBTREE_ERROR,
} node_description_t;

void tree_insert(binary_search_tree_t **bst, u32 data);
void tree_remove(binary_search_tree_t **bst, u32 data);
bool is_empty(const binary_search_tree_t *bst);
void tree_pre_order(const binary_search_tree_t *bst);
void tree_order(const binary_search_tree_t *bst);
void tree_post_order(const binary_search_tree_t *bst);
u32 count_nodes(const binary_search_tree_t *bst);
void tree_destroy(binary_search_tree_t **bst);
node_description_t verify_node_type(binary_search_tree_t *bst);

#endif