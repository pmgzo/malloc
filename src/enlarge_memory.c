/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "node.h"

int enlarge_memory(size_t size)
{
    void *last_pg_brk = sbrk(0);
    size_t i = PAGE_SIZE;

    for (; i < size; i += PAGE_SIZE);
    if (brk(last_pg_brk + i) == -1) {
        return (-1);
    }
    return (0);
}
