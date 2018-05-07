/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:07:37 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/07 16:09:24 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

static long	lp_show_large(t_alloc *zone)
{
	long	beg;
	long	end;

	beg = (long)zone->zone;
	end = (long)zone->zone + zone->size;
	miniprintf(1, "LARGE : %p\n", zone);
	miniprintf(1, "%p - %p : %d octets\n", beg, end, end - beg);
	return (end - beg);
}

static long	lp_show_ts(t_alloc *zone)
{
	long		total;
	t_partition	*part;
	long		beg;
	long		end;

	total = 0;
	if (zone->type == 1)
		miniprintf(1, "SMALL : %p\n", zone);
	else
		miniprintf(1, "TINY : %p\n", zone);
	part = zone->zone;
	while (part != NULL)
	{
		if (part->empty == 1)
		{
			beg = (long)part->ptr;
			end = (long)part->ptr + part->size;
			miniprintf(1, "%p - %p : %d octets\n", beg, end, end - beg);
			total += end - beg;
		}
		part = part->next;
	}
	return (total);
}

void		show_alloc_mem(void)
{
	t_alloc	*zone;
	long	total;

	zone = g_zone;
	total = 0;
	while (zone != NULL)
	{
		if (zone->type == 0)
			total += lp_show_large(zone);
		else
			total += lp_show_ts(zone);
		zone = zone->next;
	}
	miniprintf(1, "Total : \033[0;1m%d\033[0;0m octets\n", total);
}
