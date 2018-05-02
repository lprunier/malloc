#include "../include/malloc.h"

static char	*lp_strcpy(char *dst, const char *src)
{
	char *ret;

	ret = dst;
	while ((*dst++ = *src++))
	{
	}
	return (ret);
}

static void *lp_replace(void *ptr, size_t size)
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
            //endroit trouve
        }
		tmp = tmp - 1;
		i++;
    }
    return (NULL);
}

void        *ft_realloc(void *ptr, size_t size)
{
    void    *ret;

    ret = ptr;
    if (size > SMALL)
    {
        ret = ft_malloc(size);
        lp_strcpy(ret, ptr);
        ft_free(ptr);
    }
    else
        ret = lp_replace(ptr, size);
    return (ret);
}