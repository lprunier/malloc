#include "../include/malloc.h"
#include <stdio.h>

void    *lp_init_zone(size_t size)
{
    void    *ptr;
    t_alloc *begin;
    size_t  len_max;

    len_max = TINY * MAX * getpagesize() + SMALL * MAX * getpagesize();

printf("lenmax = %zu | size*gps = %zu\n", len_max, size * getpagesize());
    
    if (size * getpagesize() > len_max)
    {
        ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    }
    else
    {
        ptr = mmap(0, len_max, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    }
    return NULL;
}