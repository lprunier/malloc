#include "../include/malloc.h"
#include <stdio.h>

t_alloc *zone = NULL;

void    *ft_malloc(size_t size)
{
    void    *ret;

    // printf("t_alloc %d\nt_partition %d\n", sizeof(t_alloc), sizeof(t_partition));
    if (zone == NULL && size < SMALL)
    {
        // printf("\nMMAP\n\n");
        zone = lp_init_zone();
    }
    // printf("t_alloc {\n   type-%d\n   %p\n   %p\n}\n", zone->type, zone, zone->next);
    if (size >= SMALL)
    {
        // printf("%zu - large\n", size);
        ret = lp_add_large(zone, size);
        // printf("%p\n\n", ret);
    }
    else if (size >= TINY)
    {
        // printf("%zu - small\n", size);
        ret = lp_add_small(zone);
        // printf("%p\n\n", ret);
    }
    else
    {
        // printf("%zu - tiny\n", size);
        ret = lp_add_tiny(zone);
        // printf("%p\n\n", ret);
    }
    // printf("t_alloc %p {\n   zone-%p\n   type-%d\n   next-%p\n}\n", zone, zone->zone, zone->type, zone->next);
    return (ret);
}