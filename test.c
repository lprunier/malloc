#include "include/malloc.h"
#include <stdio.h>

int main(void)
{
	int		i;
	char	*addr;

	i = 0;
	// addr = (char *)ft_malloc(3000);
	// printf("%d - %p\n", i, addr);
	// addr[0] = 42;
	while (i < 1250)
	{
		addr = (char *)ft_malloc(1024);
		// printf("%d - %p\n", i, addr);
		addr[0] = 42;
		// ft_free(addr);
		i++;
	}
	return (0);
}