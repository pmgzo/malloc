#include "node.h"
#include <math.h>

lu_t sizeof_mem_attr(lu_t size)
{
    lu_t new_size = 1;

    for (int i = 0; new_size < size; i++,new_size = pow(2, i));
    return (new_size);
}