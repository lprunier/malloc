#include "../include/malloc.h"
#include <stdio.h>

/*
**  Boucle dans la zone TINY SMALL pour trouver une place au tiny
*/
static void *lp_place_tiny(t_alloc *zone)
{
    t_partition *boucle;

    boucle = zone->zone;
    while (boucle != NULL)
    {
        if (boucle->empty == 0 && boucle->small == 0)
        {
            boucle->empty = 1;
            return (boucle->ptr);
        }
        else
            boucle = boucle->next;
    }
    while (zone != NULL && zone->next != NULL)
        zone = zone->next;
    zone->next = lp_init_zone();
    return (lp_place_tiny(zone->next));
}

/*
**  Boucle pour trouver une zone TINY et SMALL
*/
void        *lp_add_tiny(t_alloc *zone)
{
    t_alloc *begin;
    void    *ptr;

    begin = zone;
    while (zone != NULL)
    {
        if (zone->type == 0)
        {
            zone = zone->next;
        }
        else
        {
            ptr = lp_place_tiny(zone);
            zone = begin;
            return (ptr);
        }
    }
    return (NULL);
}