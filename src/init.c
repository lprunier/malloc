#include "../include/malloc.h"

/*
**  Allocation d'un small
*/
static t_partition  *lp_alloc_small(long addr)
{
    t_partition *small;

    (void)addr;
    small = (t_partition *)addr;
    small->ptr = small + sizeof(t_partition);
    small->empty = 0;
    small->small = 1;
    small->next = NULL;
    return (small);
}

/*
**  Allocation d'un tiny
*/
static t_partition  *lp_alloc_tiny(long addr)
{
    t_partition *tiny;

    (void)addr;
    tiny = (t_partition *)addr;
    tiny->ptr = tiny + sizeof(t_partition);
    tiny->empty = 0;
    tiny->small = 0;
    tiny->next = NULL;
    return (tiny);
}

/*
**  Remplissage de la zone allouee avec des t_partition
*/
static void         lp_fill_zone(t_alloc *zone)
{
    t_partition *tiny;
    t_partition *small;
    int         i;

    tiny = zone->zone;
    i = -1;
    while (++i < MAX)
    {
        tiny->next = lp_alloc_tiny((long)tiny + sizeof(t_partition) + TINY);
        tiny = tiny->next;
    }
    zone->seczone = tiny + (sizeof(t_partition) + TINY);
    small = zone->seczone;
    i = -1;
    while (++i < MAX)
    {
        small->next = lp_alloc_small((long)small + sizeof(t_partition) + SMALL);
        small = small->next;
    }
}

/*
**  Initialisation de la liste t_partition
*/
static void     lp_begin_zone(t_alloc *zone)
{
    t_partition *part;

    part = (t_partition *)zone->zone;
    part->ptr = part + sizeof(t_partition);
    part->empty = 0;
    part->small = 0;
    part->next = NULL;
}

/*
**  Initialisation de la liste t_alloc
*/
void            *lp_init_zone(void)
{
    void    *ptr;
    t_alloc *begin;
    size_t  len_max;

    len_max = ((TINY + sizeof(t_partition)) + (SMALL + sizeof(t_partition))) * (MAX + 3) + sizeof(t_alloc);
    ptr = mmap(0, len_max, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    lp_bzero(ptr, len_max);
    begin = (t_alloc *)ptr;
    begin->next = NULL;
    begin->type = 1;
    begin->zone = ptr + sizeof(t_alloc);
    lp_begin_zone(begin);
    lp_fill_zone(begin);
    // printf("alloc {\n   %p\n   type-%d\n   next-%p\n}\n", begin, begin->type, begin->next);
    return begin;
}