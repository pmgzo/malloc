#ifndef _NODE_H
#define _NODE_H

#include <unistd.h>

struct node {
    // void *addr;
    unsigned free:1; //true or false
    struct node *next;
};
// } __attribute__((__packed__)); //use packed ?
typedef struct node node_t;

struct node_to_cmp {
    unsigned size;
    node_t *addr; //node addr1
};

typedef long unsigned lu_t;

#define NODE_SIZE sizeof(struct node)
#define PAGE_SIZE getpagesize() * 2

static node_t *list = NULL;
static void *next_addr;

int enlarge_memory(size_t size);
void *init_list(size_t size);
node_t *create_empty_node(void *node_addr);
void *malloc(size_t size); //return address

#endif