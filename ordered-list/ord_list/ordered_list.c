#include <stdlib.h>
#include <stdio.h>
#include "ordered_list.h"

typedef struct ordered_list {
    char info;
    struct ordered_list *next;
} ordered_list_t;


void init_list(ordered_list_t **ord_list) {
    *ord_list = NULL;
}

bool is_empty(const ordered_list_t *ord_list) {
    return (ord_list == NULL);
}

void list_insert(ordered_list_t **ord_list, char info) {
    if(is_empty(*ord_list)) {
        *ord_list = (ordered_list_t *)malloc(1 * sizeof(ordered_list_t));
        (*ord_list)->info = info;
        (*ord_list)->next = NULL;
    }
    else {
        ordered_list_t *previous = NULL;
        ordered_list_t *aux = *ord_list;
        while((aux != NULL) && (aux->info < info)) {
            previous = aux;
            aux = aux->next;
        }
        aux = (ordered_list_t *)malloc(1 * sizeof(ordered_list_t));
        if(aux == NULL) {
            puts("Error on allocation\n");
            return;
        }
        aux->info = info;
        /* it means the algorithm did not enter on while loop, so
           the info is less than all ones contained into the list 
        */
        if(previous == NULL) {
            aux->next = *ord_list;
            *ord_list = aux;
        }
        else {
            aux->next = previous->next;
            previous->next = aux;
        }
    }
}
void print_list(const ordered_list_t *ord_list) {
    if(is_empty(ord_list)) {
        printf("List is empty");
        return;
    }
    const ordered_list_t *printer = ord_list;
    while(printer != NULL) {
        printf("Element: %c\t", printer->info);
        printer = printer->next;
    }
    puts("\n\n");
}

void list_remove(ordered_list_t *ord_list, char item) {
    if(is_empty(ord_list)) {
        puts("The list is empty\n");
        return;
    }
    ordered_list_t *previous = NULL;
    ordered_list_t *aux = ord_list;
    while((aux != NULL) && (aux->info != item)) {
        previous = aux;
        aux = aux->next;
    }
    if(aux == NULL) {
        printf("The list does not contain the item: [%c]\n", item);
        return;
    }
    /* It means the item is the first */
    if(aux == ord_list) {
        ord_list = ord_list->next;
    }
    else {
        previous->next = aux->next;
    }
    free(aux);
}
void destroy_list(ordered_list_t **ord_list) {
    if(is_empty(*ord_list)) {
        printf("Empty list\n");
        return;
    }
    ordered_list_t *destructor = NULL;
    while(*ord_list != NULL) {
        destructor = *ord_list;
        *ord_list = (*ord_list)->next;
        printf("Removed: %c\t", destructor->info);
        free(destructor);
    }
    putchar('\n');
    *ord_list = NULL;
}