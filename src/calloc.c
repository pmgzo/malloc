#include "node.h"
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    size_t total_bytes;
    void *new_addr;

    write(1, "calloc\n", 7);
    
    if (!nmemb || !size)
        return (NULL);
    nmemb = sizeof_mem_attr(nmemb);
    total_bytes = sizeof_mem_attr(nmemb * size);
    new_addr = malloc(total_bytes);
    if (new_addr)
        memset(new_addr, 0, total_bytes);
    return (new_addr);
}