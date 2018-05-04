#include "include/malloc.h"

int main()
{
   ft_malloc(102);
   ft_malloc(1024);
   ft_malloc(1024 * 32);
   ft_malloc(1024 * 1024);
   ft_malloc(1024 * 1024 * 16);
   show_alloc_mem();
   return (0);
}