#include "../include/malloc.h"

static size_t   lp_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

static void	    lp_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int      lp_nblen(int i)
{
    int len;

    len = 1;
    while ((i = i / 10) > 0)
        len++;
    return (len);
}

static void     lp_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, lp_strlen(s));
}

static void     lp_putnbr_fd(long n, int fd)
{
	unsigned long nb;

	if (n < 0)
	{
		nb = -n;
		lp_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb < 10)
		lp_putchar_fd(nb + '0', fd);
	else
	{
		lp_putnbr_fd(nb / 10, fd);
		lp_putnbr_fd(nb % 10, fd);
	}
}

static int      lp_printf_string(va_list pa, int fd)
{
	char *s;

	s = va_arg(pa, char *);
	lp_putstr_fd(s, fd);
	return (lp_strlen(s));
}

static int      lp_printf_nb(va_list pa, int fd)
{
	int	i;

	i = va_arg(pa, int);
	lp_putnbr_fd(i, fd);
	return (lp_nblen(i));
}

int             miniprintf(int fd, char *str, ...)
{
	va_list	pa;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(pa, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 's' && ++i)
			ret += lp_printf_string(pa, fd);
		else if (str[i] == '%' && str[i + 1] == 'd' && ++i)
			ret += lp_printf_nb(pa, fd);
		else if (++ret)
			lp_putchar_fd(str[i], fd);
		i++;
	}
	va_end(pa);
	return (ret);
}