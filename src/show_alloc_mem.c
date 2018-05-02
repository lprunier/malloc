#include "../include/malloc.h"

static long lp_show_large(t_alloc *zone)
{
    long    beg;
    long    end;

    beg = (long)zone->zone;
    end = (long)zone->zone + zone->size;
    miniprintf(1, "LARGE : %p\n", zone);
    miniprintf(1, "%p - %p : %d octets\n", end - beg);
    return (end - beg);
}

static long lp_show_ts(t_alloc *zone)
{
    long        total;
    t_partition *part;
    long    beg;
    long    end;

    total = 0;
    if (zone->type == 1)
        miniprintf(1, "SMALL : %p\n", zone);
    else    
        miniprintf(1, "TINY : %p\n", zone);
    part = zone->zone;
    while (part != NULL)
    {
        if (part->empty == 1)
        {
            beg = (long)part->ptr;
            end = (long)part->ptr + part->size;
            miniprintf(1, "%p - %p : %d octets\n", end - beg);
            total += end - beg;
        }
        part = part->next;
    }
    return (total);
}

void        show_alloc_mem()
{
    t_alloc *zone;
    long    total;

    zone = g_zone;
    total = 0;
    while (zone != NULL)
    {
        if (zone->type == 0)
            total += lp_show_large(zone);
        else
            total += lp_show_ts(zone);
        zone = zone->next;
    }
    miniprintf(1, "Total : %d octets\n", total);
}