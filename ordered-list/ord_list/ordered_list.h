#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include <stdbool.h>

typedef struct ordered_list ordered_list_t;

void init_list(ordered_list_t **ord_list);
bool is_empty(const ordered_list_t *ord_list);
void list_insert(ordered_list_t **ord_list, char info);
void print_list(const ordered_list_t *ord_list);
void list_remove(ordered_list_t *ord_list, char item);
void destroy_list(ordered_list_t **ord_list);

#endif