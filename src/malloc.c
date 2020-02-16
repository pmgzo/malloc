#include "list.h"
#include "free.h"

void free(void *ptr)
{
    // write(1, "free\n", 5);
    if (list == NULL || ptr == NULL)
        return;
    if ((void *) list + NODE_SIZE == ptr) {
        free_from_the_head(&list, &next_addr, &nb_free);
        // write(1, "nbfree=", 7);
        // my_put_nbr(nb_free);
    }
    else {
        free_from_the_middle(ptr, list, &nb_free);
    }
    // write(1, "nbfree=", 7);
    // my_put_nbr(nb_free);
    // //  && list->next && list->next->free) {
    // write(1, "size not_free=", 14);
    // my_put_nbr(get_number_not_freed_node(list));
    // write(1, "size total=", 11);
    // my_put_nbr(get_size_list(list));
    // my_put_nbr(sbrk(0));
}

void *malloc(size_t size)
{
    void *new_addr = NULL;

    // write(1, "malloc", 6);
    // my_put_nbr(sbrk(0));
    size = sizeof_mem_attr(size);
    if (list == NULL) {
        new_addr = init_list(&list, &next_addr, size);
    } 
    else if (nb_free) {
        new_addr = find_freed_node(size, &list, &next_addr, &nb_free);
    }
    else {
        new_addr = add_new_node(size, &list, &next_addr);
    }
    return (new_addr ? new_addr + NODE_SIZE : NULL);
}