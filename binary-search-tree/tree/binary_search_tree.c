#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

typedef struct binary_search_tree {
    u32 data;
    struct binary_search_tree *left;
    struct binary_search_tree *right;
} binary_search_tree_t;


void tree_insert(binary_search_tree_t **bst, u32 data) {
    if(is_empty(*bst)) {
        *bst = (binary_search_tree_t *)malloc(1 * sizeof(binary_search_tree_t));
        /* Checks if the allocation succeeded */
        if(is_empty(*bst)) {
            printf("\nFail to allocate the tree\n");
            exit(EXIT_FAILURE);
        }
        (*bst)->data = data;
        (*bst)->left = (*bst)->right = NULL;
    }
    else 
    if(data > (*bst)->data) {
        tree_insert(&((*bst)->right), data);
    }
    else 
    if(data < (*bst)->data){
        tree_insert(&((*bst)->left), data);
    }
    else {
        puts("\nThe tree already contains this data");
    }
}

bool is_empty(const binary_search_tree_t *bst) {
    return (bst == NULL);
}

void tree_remove(binary_search_tree_t **bst, u32 data) {
    if(is_empty(*bst)) {
        puts("\nEmpty tree");
        return;
    }
    else
    if(data < (*bst)->data) {
        tree_remove(&((*bst)->left), data);
    }
    else
    if(data > (*bst)->data) {
        tree_remove(&((*bst)->right), data);
    }
    else 
    if(data == (*bst)->data){
        binary_search_tree_t **aux = bst;
        if(verify_node_type(*aux) == LEAF) {
            printf("\nRemoved data: %d\n", (*aux)->data);
            free(*aux);
            *aux = NULL;
        }
        else
        if(verify_node_type(*aux) == LEFT_ONLY) {
            printf("\nRemoved data: %d\n", (*aux)->data);
            binary_search_tree_t **node = &((*aux)->left);
            (*aux)->data = (*aux)->left->data;
            free((*aux)->left);
            *node = NULL;
        }
        else
        if(verify_node_type(*aux) == RIGHT_ONLY) {
            printf("\nRemoved data: %d\n", (*aux)->data);
            binary_search_tree_t **node = &((*aux)->right);
            (*aux)->data = (*aux)->right->data;
            free((*aux)->right);
            *node = NULL;
        }
        else
        if(verify_node_type(*aux) == ROOT) {
            printf("\nRemoved data: %d\n", (*aux)->data);
        }
    }
    else {
        printf("\nThere is no data = %d\n", data);
    }
}

void tree_pre_order(const binary_search_tree_t *bst) {
    if(is_empty(bst)) {
        return;
    }
    const binary_search_tree_t *aux = bst;
    printf("%d\t", aux->data);
    tree_pre_order(aux->left);
    tree_pre_order(aux->right);
}

void tree_order(const binary_search_tree_t *bst) {
    if(is_empty(bst)) {
        return;
    }
    const binary_search_tree_t *aux = bst;
    tree_order(aux->left);
    printf("%d\t", aux->data);
    tree_order(aux->right);
}

void tree_post_order(const binary_search_tree_t *bst) {
    if(is_empty(bst)) {
        return;
    }
    const binary_search_tree_t *aux = bst;
    tree_post_order(aux->left);
    tree_post_order(aux->right);
    printf("%d\t", aux->data);
}

u32 count_nodes(const binary_search_tree_t *bst) {
    if(is_empty(bst)) {
        puts("\nEmpty tree");
        return 0;
    }
    const binary_search_tree_t *aux = bst;
    return (1 + count_nodes(aux->left) + count_nodes(aux->right));
}

void tree_destroy(binary_search_tree_t **bst) {
    if(is_empty(*bst)) {
        puts("\nEmpty tree");
        return;
    }
}

node_description_t verify_node_type(binary_search_tree_t *bst) {
    if(bst->left != NULL && bst->right != NULL) {
        return ROOT;
    }
    else
    if(bst->left == NULL && bst->right == NULL) {
        return LEAF;
    }
    else
    if(bst->left != NULL && bst->right == NULL) {
        return LEFT_ONLY;
    }
    else
    if(bst->left == NULL && bst->right != NULL) {
        return RIGHT_ONLY;
    }
    else {
        return SUBTREE_ERROR;
    }
}