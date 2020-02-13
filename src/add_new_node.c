#include "node.h"

void *add_new_node(size_t size, node_t **list, void **next_addr)
{
    write(1, "add_new_node\n", 13);
    lu_t diff = (*next_addr) - sbrk(0); //case where next_addr > sbrk(0);
    node_t *new_node;

    if (!(diff > NODE_SIZE + size)) {
        if (~enlarge_memory(size - diff))
            return (NULL);
    }
    new_node = (*next_addr);
    new_node->next = (*list);
    (*list) = new_node;
    //move next addr
    (*next_addr) = (*next_addr) + NODE_SIZE + size;
    return new_node;
}