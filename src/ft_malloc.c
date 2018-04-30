/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:07:01 by lprunier          #+#    #+#             */
/*   Updated: 2018/04/30 15:07:12 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

static void *lp_malloc_init(size_t size)
{
    void    *ret;

	if (size <= TINY)
	{
		g_zone = lp_alloc_tiny(NULL);
		ret = lp_create_tiny(g_zone->zone, size);
	}
	else if (size <= SMALL)
	{
		g_zone = lp_alloc_small(NULL);
		ret = lp_create_small(g_zone->zone, size);
	}
	else
	{
		g_zone = lp_alloc_large(NULL, size);
		ret = g_zone->zone;
	}
    return ret;
}

void        *ft_malloc(size_t size)
{
	void    *ret;

	if (g_zone == NULL)
        ret = lp_malloc_init(size);
	else if (size <= TINY)
	{
		ret = lp_place_tiny(g_zone, size);
		ret = lp_create_tiny(ret, size);
	}
	else if (size <= SMALL)
	{
		ret = lp_place_small(g_zone, size);
		ret = lp_create_small(ret, size);
	}
	else
		ret = lp_place_large(g_zone, size);
	return (ret);
}
