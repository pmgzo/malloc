/*
** EPITECH PROJECT, 2020
** project
** File description:
** function
*/

#include <errno.h> 
#include "node.h"
#include "compute.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total_bytes = 0;

    nmemb = sizeof_mem_attr(nmemb);
    total_bytes = sizeof_mem_attr(nmemb * size);
    if (total_bytes > 4294967295) {
        errno = ENOMEM;
        return (NULL);
    }
    return realloc(ptr, total_bytes);
}
