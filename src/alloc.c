/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:07:38 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/07 15:51:45 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

void	*lp_ret_more(t_partition *part)
{
	part->empty = 2;
	return (part);
}

int		lp_find_size(void *src)
{
	t_alloc		*zone;
	t_partition	*part;

	zone = g_zone;
	while (zone != NULL)
	{
		if ((long)zone < (long)src && (long)zone + zone->size > (long)src)
		{
			if (zone->type == 0)
				return (zone->size - 16 - sizeof(t_alloc));
			part = zone->zone;
			while (part != NULL)
			{
				if (part->ptr == src)
					return (part->size);
				part = part->next;
			}
		}
		zone = zone->next;
	}
	return (0);
}

t_alloc	*lp_alloc_tiny(t_alloc *prev)
{
	void	*ptr;
	t_alloc	*zone;

	ptr = mmap(0, ST, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	zone = (t_alloc *)ptr;
	zone->next = NULL;
	zone->prev = prev;
	zone->size = ST;
	zone->type = 2;
	zone->zone = ptr + sizeof(t_alloc);
	return (zone);
}

t_alloc	*lp_alloc_small(t_alloc *prev)
{
	void	*ptr;
	t_alloc	*zone;

	ptr = mmap(0, SS, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	zone = (t_alloc *)ptr;
	zone->next = NULL;
	zone->prev = prev;
	zone->size = SS;
	zone->type = 1;
	zone->zone = ptr + sizeof(t_alloc);
	return (zone);
}

t_alloc	*lp_alloc_large(t_alloc *prev, size_t size)
{
	void	*ptr;
	t_alloc	*zone;
	long	max;

	max = size + sizeof(t_alloc) + 16;
	ptr = mmap(0, max, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	zone = (t_alloc *)ptr;
	zone->next = NULL;
	zone->size = size + sizeof(t_alloc) + 16;
	zone->prev = prev;
	zone->type = 0;
	zone->zone = ptr + sizeof(t_alloc);
	return (zone);
}
