#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdbool.h>

# include <stdio.h>

// # define GPS getpagesize()
// # define MAX 100
// # define TINY (size_t)((1 * GPS) / MAX)
// # define SMALL (size_t)((20 * GPS) / MAX)

# define TINY 128
# define SMALL 1024
# define SIZE_TINY 30 * getpagesize()
# define SIZE_SMALL 64 * getpagesize()

/********************
******STRUCTURES*****
********************/

/*
** Liste des allocations de mmap
**      zone = pointeur de la zone
**      type = 0 zone large, 1 zone small, 2 zone tiny
*/
typedef struct      s_alloc
{
    void            *zone;
    int             type;
    struct s_alloc  *next;
}                   t_alloc;

/*
** Liste de chaque zone reservee pour chaque malloc dans une alloc tiny ou small
**      ptr = pointeur sur le debut de la partition
**      empty = 0 partition vide, 1 partition occupee
**      size = taille de la zone disponible
*/
typedef struct          s_partition
{
    void                *ptr;
    bool                empty;
    size_t              size;
    struct s_partition  *next;
}                       t_partition;


/********************
******GLOBALE-S******
********************/

// t_alloc *zone = NULL;

/********************
******FONCTIONS******
********************/

/*
**  ft_malloc.c
*/
void    *ft_malloc(size_t size);

// /*
// **  init.c
// */
// // t_partition *lp_alloc_small(long addr);
// // t_partition *lp_alloc_tiny(long addr);
// // void        lp_fill_zone(t_alloc *zone);
// // void        lp_begin_zone(t_alloc *zone);
// void    *lp_init_zone(void);

// /*
// **  functions.c
// */
// void    lp_bzero(void *ptr, size_t len);

// /*
// **  tiny.c
// */
// // void        *lp_place_tiny(t_alloc *zone);
// void    *lp_add_tiny(t_alloc *zone);

// /*
// **  small.c
// */
// // void        *lp_place_small(t_alloc *zone);
// void    *lp_add_small(t_alloc *zone);

// /*
// **  large.c
// */
// void    *lp_add_large(t_alloc *zone, size_t size);

/*
**  alloc.c
*/
t_alloc *lp_alloc_tiny(void);

/*
**  create.c
*/
void    *lp_create_tiny(void *addr, size_t size);

/*
**  place.c
*/
void    *lp_place_tiny(t_alloc *zone, size_t size);

#endif
