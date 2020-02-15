#include "node.h"

node_t *find_node_to_free(void *ptr, node_t *list)
{
    node_t *browser = list;

    while (browser->next) {
        if ((void *) browser->next + NODE_SIZE == ptr)
            break;
        browser = browser->next;
    }
    return (browser);
}

int merge_freed_node(node_t *before_node_to_free, int *nb_free)
{
    node_t *head = before_node_to_free->next;
    int nb_of_merged_node = 0;

    (*nb_free)++;
    head->free = 1;
    while (head->next && head->free) {
        head = head->next;
        nb_of_merged_node++;
    }
    before_node_to_free->next = head;
    return (nb_of_merged_node);
}

int free_from_the_middle(void *ptr, node_t *list, int *nb_free)
{
    node_t *before_node_to_free = find_node_to_free(ptr, list);
    int nb_of_merged_node = 0;

    if (before_node_to_free) {
        nb_of_merged_node = merge_freed_node(before_node_to_free, nb_free);
        (*nb_free) -= nb_of_merged_node;
        return (0);
    }
    return (-1);
}