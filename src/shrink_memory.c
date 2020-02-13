#include "node.h"

void move_pg_brk(void *next_addr)
{
    while (1) {
        if (sbrk(0) - PAGE_SIZE < next_addr)
            break;
        brk(sbrk(0) - PAGE_SIZE);
    }
}