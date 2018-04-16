/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:56:14 by sklepper          #+#    #+#             */
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

static int		ft_is_negative(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		return (-1);
	}
	else
		return (1);
}

void			ft_putnbr(int nb)
{
	int				i1;
	int				i2;
	int				neg;
	char			c;
	unsigned int	n;

	if (nb == 0)
		ft_putchar('0');
	neg = ft_is_negative(nb);
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
		ft_putchar(c);
		i1--;
	}
}
