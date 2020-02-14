#ifndef _NODE_H
#define _NODE_H

#include <unistd.h>

struct node {
    // void *addr;
    unsigned free:1; //true or false
    struct node *next;
};

typedef struct node node_t;

typedef long unsigned lu_t;

struct node_to_cmp {
    lu_t size;
    node_t *addr; //node addr1
};


#define NODE_SIZE sizeof(struct node)
#define PAGE_SIZE getpagesize() * 2


int enlarge_memory(size_t size);

void *init_list(size_t size, node_t **list, void **next_addr);
node_t *create_empty_node(void *node_addr);

void *malloc(size_t size);
void free(void *ptr);

void *add_new_node(size_t size, node_t **list, void **next_addr);

void *find_and_split(size_t size, node_t **list);

void split_node(node_t *before_freed_node, size_t size);

//Math
lu_t sizeof_mem_attr(size_t size);

int is_pow_of_two(size_t size);

#endif