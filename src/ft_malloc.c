#include "../include/malloc.h"

t_alloc *zone = NULL;

void    *ft_malloc(size_t size)
{
    void    *ret;

    if (zone == NULL)
    {
        // (size > SMALL) ? ret = lp_alloc_large(size) : 0;
        if (size <= TINY)
        {
            zone = lp_alloc_tiny();
            ret = lp_create_tiny(zone->zone, size);
        }
        else if (size <= SMALL)
        {
            zone = lp_alloc_small();
            ret = lp_create_small(zone->zone, size);
        }
    }
    else if (size <= TINY)
    {
        ret = lp_place_tiny(zone, size);
        ret = lp_create_tiny(ret, size);
    }
    else if (size <= SMALL)
    {
        ret = lp_place_small(zone, size);
        ret = lp_create_small(ret, size);
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