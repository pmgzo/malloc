#include "node.h"
#include <stdio.h>
// cut
// find_free_space

int enlarge_memory(size_t size)
{
    size_t i = PAGE_SIZE;
    void *last_pgbrk = sbrk(0);

    for (; i < size + NODE_SIZE; i += PAGE_SIZE);
    if (brk(last_pgbrk + i) == -1) //check limit
        return (-1);
    // printf("la\n");
    return (0);
}

void *init_list(size_t size)
{
    void *last_pgbrk = sbrk(0);

    if (enlarge_memory(size) == -1)
        return (0);
    list = create_empty_node(last_pgbrk);
    // next_addr = (list + NODE_SIZE + size); 
    //don't forget the pow
    return (list + 24);
}

node_t *create_empty_node(void *node_addr)
{
    node_t *new_node = node_addr;

    // new_node->addr = node_addr + NODE_SIZE;
    new_node->free = 0;
    new_node->next = 0;
    return (new_node);
}



// void *add_new_node(size_t size)
// {
//     //find
//     //new part
//     // void *new_lbreak = sbrk(0);
//     node_t *new_node;// = 
//     // printf("%p\n", new_lbreak);

//     //add new_node in find
//     // if (!find and split return true if succeed) {
//         new_node = create_node(new_lbreak, size);
//     //     //split node
//     // }
//     return new_node->addr;
// }