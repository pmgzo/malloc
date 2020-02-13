#include "node.h"

void split_node(node_t *before_freed_node, size_t size)
{
    node_t *new_freed_node;
    void *node_addr = ((void *) before_freed_node->next + NODE_SIZE + size);

    new_freed_node = create_empty_node(node_addr);
    new_freed_node->next = before_freed_node->next;
    before_freed_node->next = new_freed_node;
}