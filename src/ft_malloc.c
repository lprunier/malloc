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

void        *malloc(size_t size)
{
	void    *ret;

	// write(1, "Debut Malloc\n", 13);
	if (g_zone == NULL)
        ret = lp_malloc_init(size);
	else if (size <= TINY)
	{
		// write(1, "before Place\n", 13);
		ret = lp_place_tiny(g_zone, size);
		// write(1, "After place\n", 12);
		ret = lp_create_tiny(ret, size);
		// write(1, "tiny\n", 5);

	}
	else if (size <= SMALL)
	{
		// write(1, "S -before Place\n", 16);
		ret = lp_place_small(g_zone, size);
		// write(1, "S -After place\n", 15);
		ret = lp_create_small(ret, size);
		// write(1, "small\n", 6);
	}
	else
	{
		// write(1, "LARGE place\n", 12);
		ret = lp_place_large(g_zone, size);
		// write(1, "L -After place\n", 15);

	}
	// write(1, "-----END-----\n", 14);
	// dprintf(1,"pointeur : %p\n", ret);
	return (ret);
}
