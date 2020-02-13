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
    lu_t size_btw_ptr;

    if (list == NULL)
        return (NULL);
    while (browser->next != NULL) {
        size_btw_ptr = browser->next - browser - NODE_SIZE;
        if (browser->next->free && size_btw_ptr >= size)
            change_ptr(browser, &ptr, size_btw_ptr);
        browser = browser->next;
    }
    return ptr.addr;
}

void *find_and_split(size_t size)
{
    //test this function
    node_t *before_freed_node = find_freed_node(size);
    lu_t rest = before_freed_node->next - before_freed_node - NODE_SIZE * 2; //new node + the node of the next

    if (before_freed_node && is_pow_of_two(rest)) {
        split_node(before_freed_node, size);
        return before_freed_node->next->next;
    }
    return before_freed_node ? before_freed_node->next : NULL;
}