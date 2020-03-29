/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "node.h"
#include "free.h"
#include <string.h>
#include "compute.h"

void *split_for_realloc(node_t *before_node_to_free, struct node_data data, size_t size)
{
    (*data.nb_free)++;
    split_node(before_node_to_free, size);
    return ((void *) before_node_to_free->next->next + NODE_SIZE);
}

void *alloc_new_space(node_t *before_node_to_free, size_t size)
{
    void *new_ptr = malloc(size);
    long long diff = (void *) before_node_to_free - (void *) before_node_to_free->next - NODE_SIZE;

    if (new_ptr) {
        memcpy(new_ptr, (void *) before_node_to_free->next + NODE_SIZE, diff);
        free((void *) before_node_to_free->next + NODE_SIZE);
    }
    return (new_ptr);
}

void *enlarge_first_node(struct node_data data, size_t size)
{
    long long diff = (sbrk(0) - (void *) data.list) - size;

    if (diff < 0) {
        if (enlarge_memory(diff * (-1)) == -1)
            return (NULL);
    }
    (*data.next_addr) = (void *) data.list + NODE_SIZE + size;
    return ((void *) data.list + NODE_SIZE);
}

void *realloc_first_node(size_t size, struct node_data data, void *ptr)
{
    long long diff = (*data.next_addr) - (void *) data.list - NODE_SIZE;

    if (diff > size) {
        move_next_addr((void *) data.list + NODE_SIZE + size, data.next_addr);
    }
    else if (diff < size) {
        return (enlarge_first_node(data, size));
    }
    return (ptr);
}

void *realloc_the_ptr(void *ptr, size_t size, struct node_data data)
{
    node_t *before_node_to_free = find_node_to_free(ptr, data.list);
    long long diff = 0;

    size = sizeof_mem_attr(size);
    if ((void *) data.list + NODE_SIZE == ptr) {
        return realloc_first_node(size, data, ptr);
    }
    else if (!before_node_to_free || !before_node_to_free->next)
        return (malloc(size));
    return alloc_new_space(before_node_to_free, size);
}
