/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#ifndef _NODE_H
#define _NODE_H

#include <unistd.h>
#include "compute.h"

struct node {
    // void *addr;
    unsigned free:1; //true or false
    struct node *next;
};

typedef struct node node_t;


struct node_to_cmp {
    size_t size;
    node_t *addr; //node addr1
};

struct node_data {
    node_t *list;
    void **next_addr;
    int *nb_free;
};

#define NODE_SIZE sizeof(struct node)
#define PAGE_SIZE getpagesize() * 2

//to remove
int my_put_nbr(void *nb);

int enlarge_memory(size_t size);

node_t *create_node(void *new_addr, node_t *next, int free);
void *init_list(node_t **list, void **next_addr, size_t size);

void *malloc(size_t size);

void *calloc(size_t nmemb, size_t size);

void *realloc(void *ptr, size_t size);

void *reallocarray(void *ptr, size_t nmemb, size_t size);

int move_pg_brk(void **next_addr);

void split_node(node_t *before_freed_node, size_t size);

void *find_freed_node(size_t size, node_t **list, void **next_addr, int *nb_free);

void *add_new_node(size_t size, node_t **list, void **next_addr);

void *realloc_the_ptr(void *ptr, size_t size, struct node_data data);

// size
int get_size_list(node_t *list);
int get_number_not_freed_node(node_t *list);


#endif
