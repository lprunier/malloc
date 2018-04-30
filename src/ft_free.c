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

static void lp_free_large(void *ptr)
{
	t_alloc     *large;
	int			i;

	i = 0;
	large = ptr;
	while (i <= sizeof(t_alloc) + 16)
	{
		if (large && large->zone == ptr)
		{
			if (large->prev == NULL && large->next == NULL)
				g_zone = NULL;
			if (large->prev)
				large->prev->next = large->next;
			if (large->next)
				large->next->prev = large->prev;
			munmap(large, large->size);
			return;
		}
		large = large - 1;
		i++;
	}
}

void        ft_free(void *ptr)
{
	t_partition *tmp;
	int         i;

	if (ptr == NULL)
		return;
	i = 0;
	tmp = ptr;
	while (i <= sizeof(t_partition) + 16)
	{
		if (tmp && tmp->ptr == ptr)
		{
			tmp->empty = 0;
			return;
		}
		tmp = tmp - 1;
		i++;
	}
	lp_free_large(ptr);
}
