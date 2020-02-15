#include "list.h"
#include "free.h"

void free(void *ptr)
{
    write(1, "free\n", 5);
    if (list == NULL || ptr == NULL)
        return;
    if ((void *) list + NODE_SIZE == ptr) {
        free_from_the_head(&list, &next_addr);
        nb_free -= 1;
    } 
    //else {

    // }
}

void *malloc(size_t size)
{
    void *new_addr = NULL;

    size = sizeof_mem_attr(size);
    if (list == NULL) {
        new_addr = init_list(&list, &next_addr, size);
    } 
    else if (nb_free) {
        new_addr = find_freed_node();
    }
    //  else {
    //     new_addr = add_new_node();
    // }
    return (new_addr ? new_addr + NODE_SIZE : NULL);
}