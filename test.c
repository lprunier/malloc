#include "include/malloc.h"
#include <stdio.h>

int main(void)
{
	int		i;
	char	*addr;
	t_partition	*ptr;

	i = 0;
	// addr = (char *)ft_malloc(3000);
	// printf("%d - %p\n", i, addr);
	// addr[0] = 42;
	while (i < 1024)
	{
		addr = (char *)ft_malloc(102);
		addr[0] = 42;
		// printf("%d - %p\n", i, addr);
		ft_free(addr);
		i++;
	}
	// ptr = g_zone->zone;
	// printf("%p\n\n", ptr->next);
	return (0);
}