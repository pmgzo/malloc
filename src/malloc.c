#include "node.h"

void *malloc(size_t size) //return address
{
    // write(1, "oui\n", 5);
    void *new_addr;

    if (list == NULL 
        && (new_addr = init_list(size)) == NULL) {
        return (NULL);
    }
    // else if (find_and_split()) {
    //     //find split / creer une nouvelle node
    // }
    // else //enlarge and create node

    return (new_addr);
}