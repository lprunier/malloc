#include "../include/malloc.h"

/*
**  Boucle dans la zone TINY SMALL pour trouver une place au small
*/
static void *lp_place_small(t_alloc *zone)
{
    t_partition *boucle;

    boucle = zone->seczone;
    while (boucle != NULL)
    {
        if (boucle->empty == 0 && boucle->small == 1)
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
    return (lp_place_small(zone->next));
}

/*
**  Boucle pour trouver une zone TINY et SMALL
*/
void        *lp_add_small(t_alloc *zone)
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
            ptr = lp_place_small(zone);
            zone = begin;
            return (ptr);
        }
    }
    return (NULL);
}