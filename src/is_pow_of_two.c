#include "node.h"
#include <math.h>

int is_pow_of_two(size_t size)
{
    return (sizeof_mem_attr(size) == size ? 1 : 0);
}
