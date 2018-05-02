/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:08:31 by lprunier          #+#    #+#             */
/*   Updated: 2018/04/30 15:08:37 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdbool.h>
# include <stdarg.h>

# include <stdio.h>

/*********************
 *******DEFINE-S******
 ********************/

# define TINY 128
# define SMALL 2048
# define ST 8 * getpagesize()
# define SS 64 * getpagesize()
# define SP sizeof(t_partition)

/*********************
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
	long            size;
	struct s_alloc  *next;
	struct s_alloc  *prev;
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
    int                 size_empty;
	struct s_partition  *next;
}                       t_partition;

/*********************
 ******GLOBALE-S******
 ********************/

t_alloc *g_zone;


/*********************
 ******FONCTIONS******
 ********************/

/*
 **  ft_malloc.c
 */
void    *ft_malloc(size_t size);

/*
 **  alloc.c
 */
t_alloc *lp_alloc_tiny(t_alloc *prev);
t_alloc *lp_alloc_small(t_alloc *prev);
t_alloc *lp_alloc_large(t_alloc *prev, size_t size);

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

/*
 **  ft_free.c
 */
void    ft_free(void *ptr);

/*
 **  ft_realloc.c
 */
void	*ft_realloc(void *ptr, size_t size);

/*
 **  show_alloc_mem.c
 */
void	show_alloc_mem(void);

/*
 **  print.c
 */
int		miniprintf(int fd, char *str, ...);

#endif
