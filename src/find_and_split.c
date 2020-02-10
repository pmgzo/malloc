#include "node.h"

int change_ptr(void *node_addr1, struct node_to_cmp *ptr, int size_btw_ptr)
{
    if (ptr->addr == NULL || ptr->size > size_btw_ptr) {
        ptr->size = size_btw_ptr;
        ptr->addr = node_addr1;
    }
    return (0);
}

node_t *find_freed_node(size_t size)
{
    struct node_to_cmp ptr = {0, NULL};
    node_t *browser = list;
    int size_btw_ptr;

    if (list == NULL)
        return (NULL);
    while (browser->next != NULL) {
        size_btw_ptr = browser->next - browser - NODE_SIZE;
        if (browser->next->free && size_btw_ptr >= size)
            change_ptr(browser, &ptr, size_btw_ptr);
        browser = browser->next;
    }
    return node_to_cmp.addr;
}

//ALLIGN MEMORY OF POWER OF TWO
void *find_and_split(size_t size) //return addr
{
    node_t *before_freed_node = find_freed_node(size);

    if (!before_freed_node)
        return (NULL);
    if (before_freed_node->next - before_freed_node - NODE_SIZE * 2 > 1) {
        // 
        // check if it count to split the node
        // return split_node
    }
    return before_freed_node->next->addr;
}