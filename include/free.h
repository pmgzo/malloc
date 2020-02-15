#ifndef FREE_H
#define FREE_H

#include "node.h"


void move_next_addr(void *addr, void **next_addr);

int free_from_the_head(node_t **list, void **next_addr);

void free(void *ptr);


#endif