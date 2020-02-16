#include "node.h"
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    lu_t total_bytes;
    void *new_addr;

    if (!nmemb || !size)
        return (NULL);
    nmemb = sizeof_mem_attr(nmemb);
    total_bytes = nmemb * size;
    new_addr = malloc(total_bytes);
    if (new_addr)
        memset(new_addr, 0, sizeof_mem_attr(total_bytes));
    return (new_addr);
}