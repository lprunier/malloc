#include "../include/malloc.h"
#include <stdio.h>

/*
**  Initialisation d'un maillon et mmap large
*/
static t_alloc  *lp_init_large(size_t size)
{
    size_t  len;
    void    *ptr;
    t_alloc *begin;

    len = size + sizeof(t_alloc);
    ptr = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    lp_bzero(ptr, len);
    begin = (t_alloc *)ptr;
    begin->next = NULL;
    begin->type = 0;
    begin->zone = ptr + sizeof(t_alloc);
    begin->seczone = NULL;
    return(begin);
}

/*
**  Boucle pour ajouter un maillon a la fin
*/
static void     *lp_add_zone(t_alloc *zone, size_t size)
{
    t_alloc *tmp;

    tmp = zone;
    while (tmp != NULL && tmp->next != NULL)
    {
        // printf("t_alloc %p {\n   zone-%p\n   type-%d\n   next-%p\n}\n", tmp, tmp->zone, tmp->type, tmp->next);
        tmp = tmp->next;
    }
    tmp->next = lp_init_large(size);
    return (tmp->next);
}

/*
**  Creation d'une zone large "sur mesure"
*/
void            *lp_add_large(t_alloc *zone, size_t size)
{
    t_alloc *tmp;

    if (zone == NULL)
    {
        zone = lp_init_large(size);
        tmp = zone;
    }
    else
    {
        tmp = lp_add_zone(zone, size);
    }
    return (tmp->zone);
}