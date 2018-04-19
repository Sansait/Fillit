/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:33:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/19 11:26:27 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place_tetra(t_tetro *tetra, char ***greed, int x, int y)
{
	if (*greed[x + tetra->hash[0].x][y + tetra->hash[0].y] != '.')
		return (0);
	if (*greed[x + tetra->hash[1].x][y + tetra->hash[1].y] != '.')
		return (0);
	if (*greed[x + tetra->hash[2].x][y + tetra->hash[2].y] != '.')
		return (0);
	if (*greed[x + tetra->hash[3].x][y + tetra->hash[3].y] != '.')
		return (0);
	return (1);
}

int		ft_solve_it(t_list *tetra, int sqr_size, char **greed)
{
	int		x;
	int		y;
	t_tetro	*tmp;

	tmp = tetra->content;
	if (tmp == NULL)
		return (1);
	x = 0;
	while (x <= sqr_size - tmp->width)
	{
		y = 0;
		while (y <= sqr_size - tmp->length)
		{
			if (ft_place_tetra(tmp, &greed, x, y))
			{
				if (ft_solve_it(tetra->next, sqr_size, greed))
					return (1);
			}
			y++;
		}
		x++;
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