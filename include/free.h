#ifndef FREE_H
#define FREE_H

void free(void *ptr);

void shrink_memory(void *addr);

void move_pg_brk();

#endif