#include "include/malloc.h"

int main(void)
{
    char    *str;
    int     i;
	int		size;
	int		boucle;

	boucle = 150;
	while (--boucle >= 0)
	{
		size = 120;
		str = (char *)ft_malloc(size + 1);
		i = 0;
		while (i < size)
		{
			str[i] = 'A';
			i++;
		}
		str[i] = '\0';
		// free(str);
		// write(1, str, size);
	}
	return (0);
}
