#include "free.h"
#include "node.h"

void merge_freed_node(node_t *before_freed_node)
{
    node_t *browser = before_freed_node->next->next;
    node_t *holder = before_freed_node->next;

    before_freed_node->next->free = 1;
    while (browser && browser->free) {
        holder = browser;
        browser = browser->next;
    }
    before_freed_node->next = holder;
}

void move_next_addr(void *new_addr, void **next_addr)
{
    (*next_addr) = new_addr;
}

void merge_from_the_beginning(node_t *head, node_t **list, void **next_addr)
{
    while (head && head->free) {
        move_next_addr(head, next_addr);
        head = head->next;
    }
    (*list) = head; //null or head(no freed)
}

void free_node(void *ptr, node_t **list, void **next_addr)
{
    node_t *browser = (*list);

    if ((void *) browser + NODE_SIZE == ptr) {
        browser->free = 1;
        merge_from_the_beginning(browser, list, next_addr);
        move_pg_brk((*next_addr));
        return;
    }
    while (browser != NULL) {
        if ((void *) browser->next + NODE_SIZE == ptr) {
            merge_freed_node(browser);
            break;
        }
        browser = browser->next;
    }
}