#include "node.h"

node_t *create_node(void *new_addr, node_t *next, int free)
{
    node_t *new_node = new_addr;

    new_node->next = next;
    new_node->free = free;
    return new_node;
}

void *init_list(node_t **list, void **next_addr, size_t size)
{
    void *last_pg_brk = sbrk(0);

    if (enlarge_memory(size) == -1) {
        return (NULL);
    }
    (*list) = create_node(last_pg_brk, NULL, 0);
    (*next_addr) = (void *) (*list) + NODE_SIZE + size;
    return (*list);
}