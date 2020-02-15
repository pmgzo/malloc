#include "node.h"

int change_ptr(void *node_addr1, struct node_to_cmp *ptr, int size_btw_ptr)
{
    if (ptr->addr == NULL || ptr->size > size_btw_ptr) {
        ptr->size = size_btw_ptr;
        ptr->addr = node_addr1;
    }
    return (0);
}

node_t *find_freed_node(size_t size, node_t **list)
{
    struct node_to_cmp ptr = {0, NULL};
    node_t *browser = (*list);
    lu_t size_btw_ptr = 0;

    if ((*list) == NULL)
        return (NULL);
    while (browser->next != NULL) {
        size_btw_ptr = (void *) browser - (void *) browser->next - NODE_SIZE;
        if (browser->next->free && size_btw_ptr >= size)
            change_ptr(browser, &ptr, size_btw_ptr);
        browser = browser->next;
    }
    return ptr.addr;
}


void *find_and_split(size_t size, node_t **list)
{
    //test this function
    write(1, "find_and_split\n", 15);
    node_t *before_freed_node = find_freed_node(size, list);
    long long rest = 0;

    if (before_freed_node) {
        rest = (void *) before_freed_node - (void *) before_freed_node->next - NODE_SIZE * 2 - size; //new node + the node of the next
        // write(1, "\nrest =\n", 8);
        // my_put_nbr(before_freed_node);
        // my_put_nbr(before_freed_node->next);
        // my_put_nbr((void*)before_freed_node - (void *) before_freed_node->next);
        // my_put_nbr((void *)rest);
        before_freed_node->next->free = 0;
    }
    if (rest > 0 && is_pow_of_two(rest)) {
        write(1, "split\n", 6);
        split_node(before_freed_node, size);
        return before_freed_node->next->next;
    }
    write(1, "end_find_and_split\n", 19);
    return before_freed_node ? before_freed_node->next : NULL;
}
// node_t *find_freed_node(size_t size, node_t **list)
// {
//     struct node_to_cmp pize, node_t **list)
// {
//     struct node_to_cmp ptr = {0, NULL};
//     node_t *browser = (*list);
//     lu_t size_btw_ptr;

//     if ((*list) == NULL)
//         return (NULL);
//     while (browser->next != NULL) {
//         write(1,"1", 1);
//         size_btw_ptr = browser->next - browser - NODE_SIZE;
//         write(1,"2", 1);
//         if (browser->next->free && size_btw_ptr >= size) {
//             write(1,"3", 1);
//             change_ptr(browser, &ptr, size_btw_ptr);
//         }
//         write(1,"4", 1);
//         browser = browser->next;
//     }
//     write(1, "coucou\n", 7);
//     return ptr.addr;
// }
//     if ((*list) == NULL)
//         return (NULL);
//     while (browser->next != NULL) {
//         write(1,"1", 1);
//         size_btw_ptr = browser->next - browser - NODE_SIZE;
//         write(1,"2", 1);
//         if (browser->next->free && size_btw_ptr >= size) {
//             write(1,"3", 1);
//             change_ptr(browser, &ptr, size_btw_ptr);
//         }
//         write(1,"4", 1);
//         browser = browser->next;
//     }
//     write(1, "coucou\n", 7);
//     return ptr.addr;
// }