#include "node.h"
#include "free.h"
#include <string.h>
#include "compute.h"

void *split_for_realloc(node_t *before_node_to_free, struct node_data data, size_t size)
{
    (*data.nb_free)++;
    split_node(before_node_to_free, size);
    // write(1, "here\n", 5);
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

    write(1, "enlarge node\n", 14);
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


    write(1, "realloc_first_node\n", 20);
    if (diff > size) {
        write(1, "if realoc fst node\n", 20);
        move_next_addr((void *) data.list + NODE_SIZE + size, data.next_addr);
    }
    else if (diff < size) {
        write(1, "enlarge first node\n", 19);
        return (enlarge_first_node(data, size));
    }
    return (ptr);
}

void *realloc_the_ptr(void *ptr, size_t size, struct node_data data)
{
    node_t *before_node_to_free = find_node_to_free(ptr, data.list);
    long long diff = 0;

    size = sizeof_mem_attr(size);
    write(1, "realloc size", 12);
    if ((void *) data.list + NODE_SIZE == ptr) {
        write(1, "fstnd\n", 6);
        return realloc_first_node(size, data, ptr);
    }
    else if (!before_node_to_free || !before_node_to_free->next)
        return (malloc(size));
    diff = (void *) before_node_to_free - (void *) before_node_to_free->next - NODE_SIZE * 2 - size;
    if (diff > 0 && is_pow_of_two(diff)) {
        // printf("%d---------split\n", diff);
        write(1, "split\n", 6);
        return split_for_realloc(before_node_to_free, data, size);
    } else {
        return alloc_new_space(before_node_to_free, size);
    }
}

