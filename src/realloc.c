#include "node.h"
#include "free.h"
#include <string.h>

void *split_for_realloc(node_t *before_node_to_free, struct node_data data, size_t size)
{
    (*data.nb_free)++;
    split_node(before_node_to_free, size);
    write(1, "here\n", 5);
    return ((void *) before_node_to_free->next->next + NODE_SIZE);
}

void *alloc_new_space(node_t *before_node_to_free, size_t size, long long diff)
{
    void *new_ptr = malloc(size);

    if (new_ptr) {
        memcpy(new_ptr, before_node_to_free->next, diff);
        free(before_node_to_free->next);
    }
    return (new_ptr);
}

void *enlarge_first_node(struct node_data data, size_t size)
{
    long long diff = sbrk(0) - (void *) data.list - size - NODE_SIZE;

    if (diff < 0) {
        if (enlarge_memory(diff * (-1) - NODE_SIZE) == -1)
            return (NULL);
    }
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

    if (before_node_to_free && before_node_to_free->next)
        diff = (void *) before_node_to_free - (void *) before_node_to_free->next - NODE_SIZE;
    write(1, "diff=", 5);
    my_put_nbr(diff);
    if (diff > size) {
        return split_for_realloc(before_node_to_free, data, size);
    }
    if (diff != 0 && diff < size) {
        return alloc_new_space(before_node_to_free, size, diff);
    }
    if ((void *) data.list + NODE_SIZE == ptr) {
        return realloc_first_node(size, data, ptr);
    } 
    else
        return (malloc(size));
}

