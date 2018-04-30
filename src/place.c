/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:08:10 by lprunier          #+#    #+#             */
/*   Updated: 2018/04/30 15:31:16 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

static void *lp_ret_more(t_partition *part)
{
    part->empty = 1;
    return (part);
}

static void *lp_ret_tiny_place(t_alloc *copy, t_partition *part, size_t size)
{
	while (part != NULL)
	{
		if (part->empty == 0 && part->size >= size)
			return (lp_ret_more(part));
		else if (part->next == NULL)
		{
            if (((long)part + part->size + SP * 2 + size + part->size_empty + 15) < ((long)copy + ST))
			{
                part->next = (void *)((long)part + part->size + SP + part->size_empty);
				return (part->next);
			}
			else
			{
				while (copy->next != NULL)
					copy = copy->next;
				copy->next = lp_alloc_tiny(copy);
				return (copy->next->zone);
			}
		}
		part = part->next;
	}
	return(NULL);
}

void    *lp_place_tiny(t_alloc *zone, size_t size)
{
	t_alloc     *copy;
	t_partition *part;

	copy = zone;
	while (copy != NULL)
	{
		if (copy->type == 2)
			break ;
		if (copy->next == NULL)
		{
			copy->next = lp_alloc_tiny(copy);
			return (copy->next->zone);
		}
		copy = copy->next;
	}
	part = copy->zone;
	return (lp_ret_tiny_place(copy, part, size));
}

static void *lp_ret_small_place(t_alloc *copy, t_partition *part, size_t size)
{
	while (part != NULL)
	{
		if (part->empty == 0 && part->size >= size)
			return (lp_ret_more(part));
		else if (part->next == NULL)
		{
            if (((long)part + part->size + SP * 2 + size + 15 + part->size_empty) < ((long)copy + SS))
			{
                part->next = (void *)((long)part + part->size + SP + part->size_empty);
				return (part->next);
			}
			else
			{
				while (copy->next != NULL)
					copy = copy->next;
				copy->next = lp_alloc_small(copy);
				return (copy->next->zone);
			}
		}
		part = part->next;
	}
	return (NULL);
}

void    *lp_place_small(t_alloc *zone, size_t size)
{
	t_alloc     *copy;
	t_partition *part;

	copy = zone;
	while (copy != NULL)
	{
		if (copy->type == 1)
			break ;
		if (copy->next == NULL)
		{
			copy->next = lp_alloc_small(copy);
			return (copy->next->zone);
		}
		copy = copy->next;
	}
	part = copy->zone;
	return (lp_ret_small_place(copy, part, size));
}

void    *lp_place_large(t_alloc *zone, size_t size)
{
	t_alloc *copy;

	copy = zone;
	while (copy != NULL)
	{
		if (copy->next == NULL)
		{
			copy->next = lp_alloc_large(copy, size);
			return (copy->next->zone);
		}
		copy = copy->next;
	}
	return (NULL);
}
