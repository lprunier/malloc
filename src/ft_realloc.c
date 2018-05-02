#include "../include/malloc.h"

static char	    *lp_strcpy(char *dst, const char *src)
{
	char *ret;

	ret = dst;
	while ((*dst++ = *src++))
	{
	}
	return (ret);
}

static t_alloc  *lp_find_alloc(t_partition *part)
{
    t_alloc *tmp;

    tmp = g_zone;
    while (tmp != NULL)
    {
        if ((long)part > (long)tmp && (long)part < (long)tmp + tmp->size)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

static void     *lp_replace(t_partition *part, size_t size)
{
    long    len;
    t_alloc *zone;
    void    *ret;

    len = (long)part + part->size + SP * 2 + size + 15 + part->size_empty;
    zone = lp_find_alloc(part);
    if (len < ((long)zone + zone->size))
    {
        part->size = size;
        return (part->ptr);
    }
    ret = ft_malloc(size);
    lp_strcpy(ret, part->ptr);
    ft_free(part->ptr);
    return (ret);
}

static void     *lp_find_place(void *ptr, size_t size)
{
    t_partition *tmp;
    void        *ret;
	int         i;

	i = 0;
	tmp = ptr;
	while (i <= sizeof(t_partition) + 16)
	{
		if (tmp && tmp->ptr == ptr)
		{
            if (tmp->size >= size)
                return (ptr);
            if (tmp->next != NULL)
            {
                ret = ft_malloc(size);
                lp_strcpy(ret, ptr);
                ft_free(ptr);
                return (ret);
            }
            else
                return (lp_replace(tmp, size));
        }
		tmp = tmp - 1;
		i++;
    }
    return (NULL);
}

void            *ft_realloc(void *ptr, size_t size)
{
    void    *ret;

    ret = ptr;
    if (ptr == NULL)
        return (NULL);
    if (size > SMALL)
    {
        ret = ft_malloc(size);
        lp_strcpy(ret, ptr);
        ft_free(ptr);
    }
    else
        ret = lp_find_place(ptr, size);
    return (ret);
}