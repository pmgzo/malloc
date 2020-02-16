#include "node.h"
#include "errno.h" 

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    lu_t total_bytes = 0;

    nmemb = sizeof_mem_attr(nmemb);
    total_bytes = nmemb * size;
    if (total_bytes > 4294967295) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(ptr, nmemb * size);
}