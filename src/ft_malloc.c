#include "../include/malloc.h"
#include <stdio.h>

void    *ft_malloc(size_t size)
{
    void    *ret;

    if (zone == NULL)
    {
        // (size > SMALL) ? ret = lp_alloc_large(size) : 0;
        (size <= TINY) ? ret = lp_alloc_tiny(size) : 0;
        // (size <= SMALL && size > TINY) ? ret = lp_alloc_small(size) : 0;
    }
    // if (zone == NULL && size < SMALL)
    //     zone = lp_init_zone();
    // if (size >= SMALL)
    //     ret = lp_add_large(zone, size);
    // else if (size >= TINY)
    //     ret = lp_add_small(zone);
    // else
    //     ret = lp_add_tiny(zone);
    return (ret);
}