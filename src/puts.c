/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:05:19 by lprunier          #+#    #+#             */
/*   Updated: 2018/05/07 17:20:35 by lprunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/malloc.h"

size_t	lp_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	lp_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		lp_nblen(int i)
{
	int len;

	len = 1;
	while ((i = i / 10) > 0)
		len++;
	return (len);
}

void	lp_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, lp_strlen(s));
}

void	lp_putnbr_fd(long n, int fd)
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
