#include "node.h"
#include <stdio.h>

// cut
// find_free_space
node_t *create_empty_node(void *node_addr)
{
    node_t *new_node = node_addr;

    new_node->free = 1;
    new_node->next = NULL;
    return (new_node);
}

void *init_list(size_t size)
{
    void *last_pgbrk = sbrk(0);
    node_t *rest;

    if (enlarge_memory(size) == -1)
        return (0);
    list = create_empty_node(last_pgbrk);
    list->free = 0;
    next_addr = ((void*)list + NODE_SIZE + size);
    return (list);
}
