#include "../include/malloc.h"

t_alloc *zone = NULL;

void    *ft_malloc(size_t size)
{
    void    *ret;

    if (zone == NULL)
    {
        if (size <= TINY)
        {
            printf("%zu - TINY - mmap\n", size);
            zone = lp_alloc_tiny();
            ret = lp_create_tiny(zone->zone, size);
        }
        else if (size <= SMALL)
        {
            printf("%zu - SMALL - mmap\n", size);
            zone = lp_alloc_small();
            ret = lp_create_small(zone->zone, size);
        }
        else
        {
            printf("%zu - LARGE - mmap\n", size);
            zone = lp_alloc_large(size);
            ret = zone->zone;
        }
    }
    else if (size <= TINY)
    {
        printf("%zu - TINY\n", size);
        ret = lp_place_tiny(zone, size);
        ret = lp_create_tiny(ret, size);
    }
    else if (size <= SMALL)
    {
        printf("%zu - SMALL\n", size);
        ret = lp_place_small(zone, size);
        ret = lp_create_small(ret, size);
    }
    else
    {
        printf("%zu - LARGE - mmap\n", size);
        ret = lp_place_large(zone, size);
    }
    return (ret);
}