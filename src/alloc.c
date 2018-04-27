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

t_alloc *lp_alloc_small()
{
    void    *ptr;
    t_alloc *zone;

    ptr = mmap(0, SIZE_SMALL, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    zone = (t_alloc *)ptr;
    zone->next = NULL;
    zone->type = 1;
    zone->zone = ptr + sizeof(t_alloc);
    return (zone);
}

t_alloc *lp_alloc_large(size_t size)
{
    void    *ptr;
    t_alloc *zone;
    long    max;

    max = size + sizeof(t_alloc) + 10;
    ptr = mmap(0, max, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    zone = (t_alloc *)ptr;
    zone->next = NULL;
    zone->type = 0;
    zone->zone = ptr + sizeof(t_alloc);
    return (zone);
}