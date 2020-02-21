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
    write(1, "free\n", 5);

    if (list == NULL || ptr == NULL) {
        return;
    }
    if ((void *) list + NODE_SIZE == ptr) {
        free_from_the_head(&list, &next_addr, &nb_free);
    }
    else {
        free_from_the_middle(ptr, list, &nb_free);
    }
}

void *malloc(size_t size)
{
    write(1, "malloc\n", 7);
    void *new_addr = NULL;

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
    // my_put_nbr(new_addr);
    // my_put_nbr(sbrk(0));
    // write(1, "after\n", 6);
    return (new_addr ? new_addr + NODE_SIZE : NULL);
}