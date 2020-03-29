/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include "node.h"

int get_size_list(node_t *list)
{
    int size = 0;

    while (list) {
        list = list->next;
        size++;
    }
    return (size);
}


int get_number_not_freed_node(node_t *list)
{
    int size = 0;

    while (list) {
        if(!list->free) {
            size++;
        }
        list = list->next;
    }
    return (size);
}
