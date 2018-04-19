/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:33:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/19 15:41:56 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_map(t_point hash[4], char **greed, int x, int y)
{
	if (greed[y + hash[0].y][x + hash[0].x] != '.')
		return (0);
	if (greed[y + hash[1].y][x + hash[1].x] != '.')
		return (0);
	if (greed[y + hash[2].y][x + hash[2].x] != '.')
		return (0);
	if (greed[y + hash[3].y][x + hash[3].x] != '.')
		return (0);
	return (1);
}

int		ft_solve_it(t_list *tetra, int sqr_size, char **greed)
{
	int		x;
	int		y;
	t_tetro	*tmp;

	if (tetra == NULL)
	{
		ft_puttab(greed);
		return (1);
	}
	tmp = tetra->content;
	y = 0;
	while (y <= sqr_size - tmp->length)
	{
		x = 0;
		while (x <= sqr_size - tmp->width)
		{
			if (ft_check_map(tmp->hash, greed, x, y))
			{
				greed = ft_place_tetra(tmp, greed, x, y);
				if (ft_solve_it(tetra->next, sqr_size, greed))
					return (1);
				greed = ft_remove_tetra(tmp, greed, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_solver(t_list tetra)
{
	int		sqr_size;
	char	**greed;

	sqr_size = ft_roundup_sqrt((ft_lstsize(&tetra) * 4));
	greed = ft_init_map(sqr_size);
	while (ft_solve_it(&tetra, sqr_size, greed) != 1)
	{
		sqr_size++;
		ft_memdel((void**)greed);
		greed = ft_init_map(sqr_size);
	}
	return (0);
}