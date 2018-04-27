#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdbool.h>

# include <stdio.h>

/********************
*******DEFINE-S******
********************/

# define TINY 128
# define SMALL 2048
# define SIZE_TINY 30 * getpagesize()
# define SIZE_SMALL 300 * getpagesize()

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
******FONCTIONS******
********************/

/*
**  ft_malloc.c
*/
void    *ft_malloc(size_t size);

/*
**  alloc.c
*/
t_alloc *lp_alloc_tiny(void);
t_alloc *lp_alloc_small(void);
t_alloc *lp_alloc_large(size_t size);

/*
**  create.c
*/
void    *lp_create_tiny(void *addr, size_t size);
void    *lp_create_small(void *addr, size_t size);

/*
**  place.c
*/
void    *lp_place_tiny(t_alloc *zone, size_t size);
void    *lp_place_small(t_alloc *zone, size_t size);
void    *lp_place_large(t_alloc *zone, size_t size);

#endif
