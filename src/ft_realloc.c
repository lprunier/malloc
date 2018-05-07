#include "../include/malloc.h"

static int      lp_find_size(void *src)
{
    t_alloc     *zone;
    t_partition *part;

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

static char	    *lp_memcpy(char *dst, const char *src, size_t len)
{
	char    *ret;
    size_t  i;

    i = -1;
	ret = dst;
	while (++i < len)
	{
        dst[i] = src[i];
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
    ret = malloc(size);
    lp_memcpy(ret, part->ptr, part->size);
    free(part->ptr);
    return (ret);
}

static void     *lp_find_place(void *ptr, size_t size)
{
    t_alloc     *zone;
    t_partition *part;
    void        *ret;

    zone = g_zone;
    while (zone != NULL)
    {
        if ((long)zone < (long)ptr && (long)zone + zone->size > (long)ptr)
        {
            part = zone->zone;
            while (part != NULL)
            {
                if (part->ptr == ptr && part->next != NULL)
                {
                    ret = malloc(size);
                    lp_memcpy(ret, ptr, part->size);
                    free(ptr);
                    return (ret);
                }
                else if (part->ptr == ptr)
                    return (lp_replace(part, size));
                part = part->next;
            }
        }
        zone = zone->next;
    }
    return (malloc(size));
}

void            *realloc(void *ptr, size_t size)
{
    // miniprintf(1, "debut realloc - %d - %d\n", (int)ptr, size);
    void    *ret;

    ret = ptr;
    if (ptr == NULL)
    {
        // miniprintf(1, "End ptr null\n");
        return (malloc(size));
    }
    if (size > SMALL)
    {
        ret = malloc(size);
        lp_memcpy(ret, ptr, lp_find_size(ptr));
        free(ptr);
    }
    else
        ret = lp_find_place(ptr, size);
    // miniprintf(1, "End - %d\n", (int)ret);
    return (ret);
}
