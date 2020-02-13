#ifndef FREE_H
#define FREE_H

#include "node.h"

void free_node(void *ptr, node_t **list, void **next_addr);

void move_pg_brk(void *next_addr);

// void shrink_memory(void *addr);

#endif