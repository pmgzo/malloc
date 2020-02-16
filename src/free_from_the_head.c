#include "node.h"

void move_next_addr(void *addr, void **next_addr)
{
    (*next_addr) = addr;
}

int free_from_the_head(node_t **list, void **next_addr, int *nb_free)
{
    node_t *head = (*list);
    int nb_of_merged_node = 0;

    head->free = 1;
    move_next_addr(head, next_addr);
    head = head->next;
    while (head && head->free) {
        move_next_addr(head, next_addr);
        head = head->next;
        nb_of_merged_node++;
    }
    if (nb_of_merged_node != 0)
        (*nb_free)++;
    (*nb_free) -= nb_of_merged_node;
    if (sbrk(0) - (*next_addr) >= PAGE_SIZE) {
        move_pg_brk(next_addr);
    }
    (*list) = head;
    if ((*list) == NULL) {
        (*nb_free) = 0;
    }
    return (0);
}