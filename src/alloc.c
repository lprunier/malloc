#include "../include/malloc.h"

t_alloc *lp_alloc_tiny()
{
    void    *ptr;
    t_alloc *zone;

    ptr = mmap(0, SIZE_TINY, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    zone = (t_alloc *)ptr;
    zone->next = NULL;
    zone->type = 2;
    zone->zone = ptr + sizeof(t_alloc);
    return (zone);
}