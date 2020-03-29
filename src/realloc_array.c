#include <errno.h> 
#include "node.h"
#include "compute.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total_bytes = 0;

    write(1, "realloc array\n", 15);

    nmemb = sizeof_mem_attr(nmemb);
    total_bytes = sizeof_mem_attr(nmemb * size);
    if (total_bytes > 4294967295) {
        write(1, "superior\n", 10);
        errno = ENOMEM;
        return (NULL);
    }
    write(1, "superior\n", 10);
    return realloc(ptr, total_bytes);
}