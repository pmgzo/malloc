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

node_t *return_head_of_merged_node(node_t *head, int *nb_of_merged_node)
{
    node_t *browser = head->next;

    while (browser && browser->free) {
        head = browser;
        (*nb_of_merged_node)++;
        browser = browser->next;
    }
    return (head);
}

int merge_freed_node(node_t *before_node_to_free, int *nb_free)
{
    node_t *head = before_node_to_free->next;
    int nb_of_merged_node = 0;

    (*nb_free)++;
    head->free = 1;
    before_node_to_free->next = return_head_of_merged_node(head, &nb_of_merged_node);
    return (nb_of_merged_node);
}

int free_from_the_middle(void *ptr, node_t *list, int *nb_free)
{
    node_t *before_node_to_free = find_node_to_free(ptr, list);
    int nb_of_merged_node = 0;

    if (before_node_to_free->next) {
        nb_of_merged_node = merge_freed_node(before_node_to_free, nb_free);
        (*nb_free) -= nb_of_merged_node;
        return (0);
    }
    return (-1);
}