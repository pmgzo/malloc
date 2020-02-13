#include "free.h"
#include "node.h"

void merge_freed_node(node_t *before_freed_node)
{
    node_t *after_freed_node = before_freed_node->next;

    before_freed_node->next->free = 1; 
    if (after_freed_node && after_freed_node->free) {
        before_freed_node->next = after_freed_node;
    }
}

void move_next_addr(void *new_addr)
{
    next_addr = new_addr;
}

void merge_from_the_beginning(node_t *head)
{
    node_t *before_current_node = NULL;

    while (head->next && head->free) {
        if (!head->next->free) {
            list = head->next;
            break;
        }
        move_next_addr(head);
        before_current_node = head;
        head = head->next;
    }
    if (!head->next && before_current_node) {
        list = head;
        move_next_addr(before_current_node);
    }
}

void free_node(void *ptr)
{
    node_t *browser = list;

    if ((void *) browser + NODE_SIZE == ptr) {
        browser->free = 1;
        merge_from_the_beginning(browser);
        move_pg_brk();
        return;
    } 
    while (browser != NULL) {
        if ((void *) browser->next + NODE_SIZE == ptr) {
            fuse_freed_node(before_freed_node);
            break;
        }
        browser = browser->next;
    }
}