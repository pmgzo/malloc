#include "node.h"
#include <math.h>

long unsigned determine_node_size(size_t size)
{
    lu_t new_size = 1;

    for (int i = 0; 
        new_size < size + NODE_SIZE; i++,new_size = pow(2, i));
    return new_size;
}