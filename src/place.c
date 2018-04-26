#include "../include/malloc.h"

void    *lp_place_tiny(t_alloc *zone, size_t size)
{
    t_alloc     *copy;
    t_partition *part;

    copy = zone;
    while (copy != NULL)
    {
        if (copy->type == 2)
            break;
        if (copy->next == NULL)
        {
            copy->next = lp_alloc_tiny();
            return(copy->next->zone);
        }
        copy = copy->next;
    }
    part = copy->zone;
    while (part != NULL)
    {
        if (part->empty == 0 && part->size > size)
        {
            part->empty = 1;
            return(part->ptr);
        }
        else if (part->next == NULL)
        {
            if (((long)part + part->size + sizeof(t_partition) * 2 + size) < ((long)copy + SIZE_TINY))
            {
                part->next = (long)part + part->size + sizeof(t_partition);
                return(part->next);
            }
            else
            {
                while (copy->next != NULL)
                    copy = copy->next;
                copy->next = lp_alloc_tiny();
                return(copy->next->zone);
            }
        }
        part = part->next;
    }
    return(NULL);
}