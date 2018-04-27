#include "include/malloc.h"
#include <stdio.h>

int main(void)
{
	int		i;
	int		len;
	char	*addr;

	i = 0;
	len = 1;
	while (i < 100)
	{
		addr = (char *)ft_malloc(len);
		len += 40;
		printf("%d - %p\n", i, addr);
		addr[0] = 42;
		i++;
	}
	return (0);
}