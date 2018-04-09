#include "../include/malloc.h"

t_alloc *zone = NULL;

void    *ft_malloc(size_t size)
{
    if (zone == NULL)
    {
        write(1, "zone nulle\n", 12);
        zone = lp_init_zone(size);
    }
    else
        write(1, "ok\n", 4);

    void    *ptr;
    ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    return (ptr);
    // return (NULL);
}



    // void    *ptr;
    // ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    // return (ptr);
