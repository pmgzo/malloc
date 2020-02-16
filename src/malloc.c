#include "list.h"
#include "free.h"

void *realloc(void *ptr, size_t size)
{
    struct node_data data = {list, &next_addr, &nb_free};

    size = sizeof_mem_attr(size);
    if (ptr == NULL) {
        return (malloc(size));
    }
    else if (size == 0) {
        free(ptr);
        return (NULL);
    } else
        return realloc_the_ptr(ptr, size, data);
}

void free(void *ptr)
{
    // write(1, "free\n", 5);

    if (list == NULL || ptr == NULL) {
        return;
    }
    if ((void *) list + NODE_SIZE == ptr) {
        free_from_the_head(&list, &next_addr, &nb_free);
    }
    else {
        free_from_the_middle(ptr, list, &nb_free);
    }
    // write(1, "after free\n", 11);

    // write(1, "size list", 9);
    // my_put_nbr(get_size_list(list));
    // write(1, "not freed", 9);
    // my_put_nbr(get_number_not_freed_node(list));
    
}

void *malloc(size_t size)
{
    void *new_addr = NULL;

    // write(1, "malloc\n", 7);

    // my_put_nbr(size);
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
    // write(1, "aftermalloc\n", 12);

    return (new_addr ? new_addr + NODE_SIZE : NULL);
}