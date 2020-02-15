#include "node.h"

void move_next_addr(void *addr, void **next_addr)
{
    (*next_addr) = addr;
}

int free_from_the_head(node_t **list, void **next_addr)
{
    node_t *head = (*list);

    head->free = 1;
    while (head && head->free) {
        move_next_addr(head, next_addr);
        head = head->next;
    }
    if (sbrk(0) - (*next_addr) >= PAGE_SIZE)
        move_pg_brk(next_addr);
    (*list) = head;
    return (0);
}