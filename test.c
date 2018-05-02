#include "include/malloc.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define M (1024 * 1024)

void print(char *s)
{
   write(1, s, strlen(s));
}

int     main()
{
   char *addr1;
   char *addr3;

   addr1 = (char*)ft_malloc(16*M);
   strcpy(addr1, "Bonjours\n");
   print(addr1);
   addr3 = (char*)ft_realloc(addr1, 128*M);
   addr3[127*M] = 42;
   print(addr3);
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