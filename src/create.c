#include "../include/malloc.h"

void    *lp_create_tiny(void *addr, size_t size)
{
    t_partition *link;

    link = (t_partition *)addr;
    link->next = NULL;
    link->empty = 1;
    link->size = size;
    link->ptr = addr + sizeof(t_partition);
    return(link->ptr);
}