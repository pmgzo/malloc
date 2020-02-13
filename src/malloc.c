#include "node.h"

void *malloc(size_t size) //return address
{
    write(1, "mon_malloc\n", 11);
    void *new_addr;

    size = sizeof_mem_attr(size); //allign
    if (list == NULL) { 
        new_addr = init_list(size);
    }
    else if (!(new_addr = find_and_split(size))) { //find split / creer une nouvelle node
        write(1, "ici\n", 4);
        new_addr = add_new_node(size);
        //enlarge
    }
    write(1, "mon_malloc\n", 11);    
    return new_addr ? (new_addr + NODE_SIZE) : NULL;
}