#include "node.h"

int enlarge_memory(size_t size)
{
    size_t i = PAGE_SIZE;
    void *last_pgbrk = sbrk(0);

    // size = sizeof_mem_attr(size); //called in malloc
    for (; i < size + NODE_SIZE; i += PAGE_SIZE);
    if (brk(last_pgbrk + i) == -1) //check limit
        return (-1);
    return (0);
}