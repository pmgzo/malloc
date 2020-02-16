#include "node.h"


void change_ptr(struct node_to_cmp *ptr, node_t *before_freed_node, size_t size_btw_ptr)
{
    if (ptr->addr == NULL || size_btw_ptr < ptr->size) {
        ptr->addr = before_freed_node;
        ptr->size = size_btw_ptr;
    }
}

node_t *find_the_best_fit(node_t *list, size_t size)
{
    struct node_to_cmp ptr = {0, NULL};
    node_t *browser = list;
    size_t size_btw_ptr = 0;

    while (browser->next) {
        size_btw_ptr = (void *) browser - (void *) browser->next - NODE_SIZE;
        if (browser->next->free && size_btw_ptr >= size) {
            change_ptr(&ptr, browser, size_btw_ptr);
        }
        browser = browser->next;
    }
    return (ptr.addr);
}

void *check_if_we_can_split(int *nb_free, node_t *before_freed_node, size_t size)
{
    long long diff = (void *) before_freed_node - (void *) before_freed_node->next - NODE_SIZE * 2;

    before_freed_node->next->free = 0;
    (*nb_free)--;
    if (diff > 0) {
        split_node(before_freed_node, size);
        (*nb_free)++;
        return (before_freed_node->next->next);
    }
    return (before_freed_node->next);
}

void *find_freed_node(size_t size, node_t **list, void **next_addr, int *nb_free)
{
    node_t *before_freed_node = find_the_best_fit((*list), size);

    if (before_freed_node) {
        //return directly or split and return
        return (check_if_we_can_split(nb_free, before_freed_node, size));
    }
    else  {
        return (add_new_node(size, list, next_addr));
    }
}