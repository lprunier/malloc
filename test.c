#include "include/malloc.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

// int main()
// {
// 	void	*tmp;
//    ft_malloc(1000);
//    ft_malloc(1024);
//    ft_malloc(1060);
//    ft_malloc(100);
//    tmp = ft_malloc(102);
//    ft_malloc(106);
//    ft_malloc(1024 * 32);
//    ft_free(tmp);
//    show_alloc_mem();
//    return (0);
// }


int      main()
{
   int   i;
   char  *addr;

   i = 0;
   while (i < 1024)
   {
        addr = (char*)ft_malloc(1024);
        addr[0] = 42;
        ft_free(addr);
        i++;
   }
   return (0);
}