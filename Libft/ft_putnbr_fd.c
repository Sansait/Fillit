/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:36:16 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		ft_is_negative(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		return (-1);
	}
	else
		return (1);
}

void			ft_putnbr_fd(int nb, int fd)
{
	int				i1;
	int				i2;
	int				neg;
	char			c;
	unsigned int	n;

	if (nb == 0)
		ft_putchar_fd('0', fd);
	neg = ft_is_negative(nb, fd);
	i1 = ft_count(nb);
	while (i1 > 0)
	{
		i2 = i1 - 1;
		n = neg * nb;
		while (i2 > 0)
		{
			n = n / 10;
			i2--;
		}
		c = (n % 10) + '0';
		ft_putchar_fd(c, fd);
		i1--;
	}
}
