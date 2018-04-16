#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdbool.h>

# define GPS getpagesize()
# define MAX 105
# define TINY (size_t)((1 * GPS) / MAX)
# define SMALL (size_t)((20 * GPS) / MAX)
// # define TINY 6328
// # define SMALL 12600

/********************
******STRUCTURES*****
********************/

/*
** Liste des allocations de mmap
**      zone = pointeur de la zone
**      type = 0 zone large, 1 zone tiny et small
**      seczone = pointeur de la seconde zone si l'alloc est scindee
*/
typedef struct      s_alloc
{
    void            *zone;
    bool            type;
    void            *seczone;
    struct s_alloc  *next;
}                   t_alloc;

/*
** Liste de chaque zone reservee pour chaque malloc dans une alloc 1
**      ptr = pointeur sur le debut de la partition
**      empty = 0 partition vide, 1 partition occupee
**      type = 0 tiny, 1 small
*/
typedef struct          s_partition
{
    void                *ptr;
    bool                empty;
    bool                small;
    struct s_partition  *next;
}                       t_partition;



/********************
******FONCTIONS******
********************/

/*
**  ft_malloc.c
*/
void    *ft_malloc(size_t size);

/*
**  init.c
*/
// t_partition *lp_alloc_small(long addr);
// t_partition *lp_alloc_tiny(long addr);
// void        lp_fill_zone(t_alloc *zone);
// void        lp_begin_zone(t_alloc *zone);
void    *lp_init_zone(void);

/*
**  functions.c
*/
void    lp_bzero(void *ptr, size_t len);

/*
**  tiny.c
*/
// void        *lp_place_tiny(t_alloc *zone);
void    *lp_add_tiny(t_alloc *zone);

/*
**  small.c
*/
// void        *lp_place_small(t_alloc *zone);
void    *lp_add_small(t_alloc *zone);

/*
**  large.c
*/
void    *lp_add_large(t_alloc *zone, size_t size);

#endif
