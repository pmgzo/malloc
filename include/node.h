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

//to remove
int my_put_nbr(void *nb);

lu_t sizeof_mem_attr(lu_t size);

int enlarge_memory(size_t size);

node_t *create_node(void *new_addr, node_t *next, int free);
void *init_list(node_t **list, void **next_addr, size_t size);

void *malloc(size_t size);

void *calloc(size_t nmemb, size_t size);

int move_pg_brk(void **next_addr);

//
void split_node(node_t *before_freed_node, size_t size);

void *find_freed_node(size_t size, node_t **list, void **next_addr, int *nb_free);

void *add_new_node(size_t size, node_t **list, void **next_addr);
// size
int get_size_list(node_t *list);
int get_number_not_freed_node(node_t *list);


#endif