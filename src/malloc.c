#include "list.h"

void *test_malloc(size_t size)
{
    write(1, "mon_malloc\n", 11);
    void *new_addr;

    size = sizeof_mem_attr(size); //allign
    if (list == NULL) { 
        // write(1, "ok\n", 3);
        new_addr = init_list(size, &list, &next_addr);
    }
    // else if (!(new_addr = find_and_split(size))) {
    //     // write(1, "ici\n", 4);
    //     new_addr = add_new_node(size);
    // }
    // if (list == NULL)
    //     write(1,"c'est null\n", 11);
    // printf("a = %d\n", a);
    // char c = a + 48;
    // write(1, &c, 1);
    return new_addr ? (new_addr + NODE_SIZE) : NULL;
}