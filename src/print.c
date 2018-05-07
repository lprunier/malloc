/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:05:19 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/07 16:07:30 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

static void		lp_putptr_fd(unsigned long ptr, int fd)
{
	if (ptr < 16)
	{
		if (ptr < 10)
			lp_putchar_fd(ptr + '0', fd);
		else
			lp_putchar_fd(ptr - 10 + 'A', fd);
	}
	else
	{
		lp_putptr_fd(ptr / 16, fd);
		lp_putptr_fd(ptr % 16, fd);
	}
}

static int		lp_printf_string(va_list pa, int fd)
{
	char *s;

	s = va_arg(pa, char *);
	lp_putstr_fd(s, fd);
	return (lp_strlen(s));
}

static int		lp_printf_nb(va_list pa, int fd)
{
	int	i;

	i = va_arg(pa, int);
	lp_putnbr_fd(i, fd);
	return (lp_nblen(i));
}

static int		lp_printf_ptr(va_list pa, int fd)
{
	unsigned long	ptr;
	int				i;

	ptr = va_arg(pa, unsigned long);
	lp_putchar_fd('0', fd);
	lp_putchar_fd('x', fd);
	lp_putptr_fd(ptr, fd);
	i = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (2 + i);
}

int				miniprintf(int fd, char *str, ...)
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
		else if (str[i] == '%' && str[i + 1] == 'p' && ++i)
			ret += lp_printf_ptr(pa, fd);
		else if (++ret)
			lp_putchar_fd(str[i], fd);
		i++;
	}
	va_end(pa);
	return (ret);
}
