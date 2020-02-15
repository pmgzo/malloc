#include "node.h"

void split_node(node_t *before_freed_node, size_t size)
{
    void *new_addr = (void *) before_freed_node->next + NODE_SIZE + size;
    node_t *new_node = create_node(new_addr, before_freed_node->next, 1);

    before_freed_node->next = new_node;
}