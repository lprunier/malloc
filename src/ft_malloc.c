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

static void	lp_bzero(void *s, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = '\0';
		--n;
		++temp;
	}
}

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
	miniprintf(1, "\nEntree MALLOC\n");
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
	miniprintf(1, "Sortie MALLOC\n");
	return (ret);
}

void	*calloc(size_t count, size_t size)
{
	miniprintf(1, "\nEntree CALLOC\n");
	void	*ptr;

	ptr = malloc(count * size);
	lp_bzero(ptr, count * size);
	miniprintf(1, "Sortie CALLOC\n");
	return (ptr);
}
