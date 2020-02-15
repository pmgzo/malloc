#include "list.h"
#include "free.h"

void free(void *ptr)
{
    write(1, "in free\n", 8);
     write(1, "node freed = ", 13);
    my_put_nbr(ptr);

    if (list == NULL || ptr == NULL)
        return;
    else
        free_node(ptr, &list, &next_addr);
}

void *malloc(size_t size)
{
    void *new_addr;

    size = sizeof_mem_attr(size);
    if (list == NULL) { 
        // write(1, "ok\n", 3);
        new_addr = init_list(size, &list, &next_addr);
    }
    else if (!(new_addr = find_and_split(size, &list))) {
        new_addr = add_new_node(size, &list, &next_addr);
    }
    write(1, "sbrk=", 5);
    my_put_nbr(sbrk(0));
    write(1, "newaddr=", 8);
    my_put_nbr(new_addr);
    
    return (new_addr ? (new_addr + NODE_SIZE) : NULL);
}