#include "node.h"

void shrink_memory(void *addr)
{
    while (addr < sbrk(0))
        brk(sbrk(0) - PAGE_SIZE);
}

void move_pg_brk()
{
    while (1) {
        if (sbrk(0) - PAGE_SIZE > next_addr)
            break;
        brk(sbrk(0) - PAGE_SIZE);
    }
}