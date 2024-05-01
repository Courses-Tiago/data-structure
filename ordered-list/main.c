#include <stdlib.h>
#include <stdio.h>
#include <ordered_list.h>

int main(void) {
    ordered_list_t *list;
    init_list(&list);
    list_insert(&list, 'X');
    list_insert(&list, 'A');
    list_insert(&list, 'D');
    list_insert(&list, 'Z');
    list_insert(&list, 'M');
    list_remove(list, 'V');
    print_list(list);
    list_remove(list, 'D');
    list_remove(list, 'Z');
    destroy_list(&list);
    if(list == NULL) {
        puts("Memory deallocated successfully\n");
    }
    return EXIT_SUCCESS;
}