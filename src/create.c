/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:07:52 by lprunier          #+#    #+#             */
/*   Updated: 2018/04/30 15:07:56 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

void    *lp_create_tiny(void *addr, size_t size)
{
    t_partition *link;
    void        *p;

	link = (t_partition *)addr;
    if (link->empty == 2)
        return (link->ptr);
    link->next = NULL;
	link->empty = 1;
    link->size = size;
    p = addr + sizeof(t_partition);
    while ((long)p % 16 != 0)
        p = p + 1;
    link->ptr = p;
    link->size_empty = (long)link->ptr - sizeof(t_partition) - (long)link;
	return(link->ptr);
}

void    *lp_create_small(void *addr, size_t size)
{
    t_partition *link;
    void        *p;

	link = (t_partition *)addr;
    if (link->empty == 2)
        return (link->ptr);
	link->next = NULL;
	link->empty = 1;
    link->size = size;
    p = addr + sizeof(t_partition);
    while ((long)p % 16 != 0)
        p = p + 1;
	link->ptr = p;
    link->size_empty = (long)link->ptr - sizeof(t_partition) - (long)link;
	return(link->ptr);
}