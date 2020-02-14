#include "node.h"
// #include <stdio.h>

node_t *create_empty_node(void *node_addr)
{
    node_t *new_node = node_addr;

    new_node->free = 1;
    new_node->next = NULL;
    return (new_node);
}

void *init_list(size_t size, node_t **list, void **next_addr)
{
    void *last_pgbrk = sbrk(0);
    // node_t *rest;

    // if ((*list) == NULL)
    //     write(1,"initlist\n", 11);
    if (enlarge_memory(size) == -1)
        return (0);
    if (sbrk(0) == last_pgbrk)
        write(1, "oui\n", 4);
    // write(1, &((char) sizeof(list)), 1);
    (*list) = create_empty_node(last_pgbrk);
    (*list)->free = 0;
    (*next_addr) = ((void *) (*list) + NODE_SIZE + size);
    return (list);
}
