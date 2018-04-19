/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:05:38 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/19 12:47:29 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_int(char *name, int value)
{
	ft_putstr(name);
	ft_putnbr(value);
}

void	print_pos_set(t_point set[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		print_int("\nPoint nb :", i);
		print_int("\t\tx:", set[i].x);
		print_int("\ty:", set[i].y);
		i++;
	}
	ft_putchar('\n');
}

void	print_tetro(t_tetro node)
{
	print_pos_set(node.hash);
	print_int("node length:", node.length);
	print_int("\t\tnode width:", node.width);
	ft_putstr("\nnode char:");
	ft_putchar(node.c);
	ft_putchar('\n');
}

void	print_lst_tetro(t_list *lst_tetro)
{
	t_tetro *tmp;

	while (lst_tetro)
	{
		tmp = lst_tetro->content;
		print_tetro(*tmp);
		lst_tetro = lst_tetro->next;
	}
}
