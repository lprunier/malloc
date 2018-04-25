#include "../include/malloc.h"

void    *lp_init_tiny(size_t size)
{
    void    *ptr;

    ptr = mmap(0, SIZE_TINY, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    zone = (t_alloc *)ptr;
    zone->next = NULL;
    // zone->
}