#include "node.h"
#include "free.h"

//shrink memory
void handle_single_node(void *ptr)
{
    void *addr = list;

    list = NULL;
    shrink_memory(addr);
}

void free(void *ptr)
{
    if (list == NULL && ptr == NULL)
        return;
    // else if (list->next == NULL)
    else  {
        
    }
}