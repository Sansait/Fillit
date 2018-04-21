/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 23:18:58 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/21 23:19:01 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allocation of the square and initilisation of every caracter at '.'
*/

char	**ft_init_map(int sqr_s)
{
	char	**map;
	int		i;

	if (!(map = malloc(sizeof(char *) * (sqr_s + 1))))
		ft_exit_clean();
	i = 0;
	while (i < sqr_s)
	{
		if (!(map[i] = ft_memset(ft_strnew((size_t)sqr_s), '.', (size_t)sqr_s)))
			ft_exit_clean();
		i++;
	}
	map[i] = 0;
	return (map);
}

/*
** Free that map
*/

void	ft_delete_map(char ***greed, int sqr_size)
{
	while (sqr_size)
	{
		ft_strdel(&(*greed)[sqr_size - 1]);
		sqr_size--;
	}
	free(*greed);
	*greed = NULL;
}

/*
** Placing the tetra on the map for the next recursive
*/

char	**ft_place_tetra(t_tetro *tetra, char **greed, int x, int y)
{
	greed[y + tetra->hash[0].y][x + tetra->hash[0].x] = tetra->c;
	greed[y + tetra->hash[1].y][x + tetra->hash[1].x] = tetra->c;
	greed[y + tetra->hash[2].y][x + tetra->hash[2].x] = tetra->c;
	greed[y + tetra->hash[3].y][x + tetra->hash[3].x] = tetra->c;
	return (greed);
}

/*
** Removing the tetra from the map
*/

char	**ft_remove_tetra(t_tetro *tetra, char **greed, int x, int y)
{
	greed[y + tetra->hash[0].y][x + tetra->hash[0].x] = '.';
	greed[y + tetra->hash[1].y][x + tetra->hash[1].x] = '.';
	greed[y + tetra->hash[2].y][x + tetra->hash[2].x] = '.';
	greed[y + tetra->hash[3].y][x + tetra->hash[3].x] = '.';
	return (greed);
}

/*
** Finding the first square to test
*/

int		ft_roundup_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}
