#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdbool.h>

# define TINY 100
# define SMALL 500
# define MAX 110

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
*/
typedef struct          s_partition
{
    void                *ptr;
    bool                empty;
    struct s_partition  *next;
}                       t_partition;


/*
**  FONCTIONS
*/

/*
**  ft_malloc.c
*/
void    *ft_malloc(size_t size);

/*
**  init.c
*/
void    *lp_init_zone(size_t size);


#endif
