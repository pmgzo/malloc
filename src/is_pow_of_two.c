#include "node.h"
#include <math.h>

int is_pow_of_two(size_t size)
{
    lu_t pow2 = 1;

    for (int i = 1; pow2 < size; i++,pow2 = pow(2, i));
    if (pow2 == size)
        return (1);
    return (0);
}
