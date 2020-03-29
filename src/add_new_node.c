#include "node.h"

void *add_new_node(size_t size, node_t **list, void **next_addr)
{
    long long diff = sbrk(0) - (*next_addr) - size - NODE_SIZE;
    node_t *new_node;

    // write(1, "new node\n", 10);
    if (diff < 0) {
        if (enlarge_memory(diff * (-1)) == -1) {
            return (NULL);
        }
    }
    new_node = create_node((*next_addr), (*list), 0);
    (*list) = new_node;
    (*next_addr) = (*next_addr) + NODE_SIZE + size;
    return (new_node);
}