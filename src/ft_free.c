/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:08:00 by lprunier          #+#    #+#             */
/*   Updated: 2018/04/30 15:08:04 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

static void	lp_free_large(t_alloc *zone, void *ptr)
{
	if (zone->zone != ptr)
		return ;
	if (zone->prev == NULL && zone->next == NULL)
		g_zone = NULL;
	else if (zone->prev == NULL)
		g_zone = zone->next;
	else
	{
		if (zone->prev)
			zone->prev->next = zone->next;
		if (zone->next)
			zone->next->prev = zone->prev;
		munmap(zone, zone->size);
	}
}

static void	lp_free_ts(t_alloc *zone, void *ptr)
{
	t_partition	*part;

	part = zone->zone;
	while (part != NULL)
	{
		if (part->ptr == ptr)
		{
			// printf("\npart->ptr  =  %p\npart->empty = %i\n", part->ptr, part->empty);
			part->empty = 0;
			return ;
		}
		part = part->next;
	}
}

void		free(void *ptr)
{
	// return ;
	t_alloc	*zone;

	zone = g_zone;
	while (zone != NULL)
	{
		if ((long)ptr > (long)zone && (long)ptr < (long)zone + zone->size)
		{
			if (zone->type == 0)
			{
				lp_free_large(zone, ptr);
			}
			else
			{
				lp_free_ts(zone, ptr);
			}
			return ;
		}
		zone = zone->next;
	}
}
