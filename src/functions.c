#include "../include/malloc.h"

/*
**  mettre tout les octets de ptr a ptr + len a '\0'
*/
void    lp_bzero(void *ptr, size_t len)
{
    int i;

    i = 0;
    while (i < len)
    {
        ptr = 0;
        ptr++;
        i++;
    }
}