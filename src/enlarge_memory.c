#include "node.h"

int enlarge_memory(size_t size)
{
    void *last_pg_brk = sbrk(0);
    lu_t i = PAGE_SIZE;

    for (; i < size + NODE_SIZE; i++);
    if (brk(last_pg_brk + i) == -1) {
        return (-1);
    }
    return (0);
}