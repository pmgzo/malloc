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


#endif