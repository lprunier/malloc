#include "include/malloc.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main()
{
	void	*tmp;
   ft_malloc(1000);
   ft_malloc(1024);
   ft_malloc(1060);
   ft_malloc(100);
   tmp = ft_malloc(102);
   printf("%p\n", tmp);
   ft_malloc(106);
   ft_malloc(1024 * 32);
   ft_free(tmp);
//    ft_malloc(1024 * 1024);
//    ft_malloc(1024 * 1024 * 16);
//    ft_malloc(1024 * 1024 * 128);
   show_alloc_mem();
   return (0);
}


// int main(void)
// {
// 	int		i;
// 	char	*addr;
// 	t_partition	*ptr;

// 	i = 0;
// 	// addr = (char *)ft_malloc(3000);
// 	// printf("%d - %p\n", i, addr);
// 	// addr[0] = 42;
// 	while (i < 1024)
// 	{
// 		addr = (char *)ft_malloc(102);
// 		addr[0] = 42;
// 		// printf("%d - %p\n", i, addr);
// 		ft_free(addr);
// 		i++;
// 	}
// 	// ptr = g_zone->zone;
// 	// printf("%p\n\n", ptr->next);
// 	return (0);
// }