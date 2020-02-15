#include "node.h"

void *add_new_node(size_t size, node_t **list, void **next_addr)
{
    node_t *new_node;
    long long diff = (*next_addr) + size - sbrk(0);

    write(1, "add_new_node\n", 13);
    if (diff > 0) {
        write(1, "nextaddr=", 9);
        my_put_nbr((*next_addr));
        write(1, "sbrk=", 5);
        my_put_nbr(sbrk(0));
        write(1, "diff=", 5);
        my_put_nbr((void*)diff);
        write(1, "\n1\n", 3);
        if (enlarge_memory(diff) == -1)
            return (NULL);
    }
    // write(1, "ne\nt_addr =", 3);
    new_node = (*next_addr);
    new_node->next = (*list);
    new_node->free = 0;
    (*list) = new_node;
    //move next addr
    (*next_addr) = (*next_addr) + NODE_SIZE + size;
    write(1, "next_addr =", 11);
    my_put_nbr((*next_addr));
    return new_node;
}