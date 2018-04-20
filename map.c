/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:14:37 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/19 15:26:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_init_map(int sqr_size)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (sqr_size + 1));
	i = 0;
	while (i < sqr_size)
	{
		map[i] = ft_memset(ft_strnew((size_t)sqr_size), '.', (size_t)sqr_size);
		i++;
	}
	map[i] = 0;
	return (map);
}

char	**ft_place_tetra(t_tetro *tetra, char **greed, int x, int y)
{
	greed[y + tetra->hash[0].y][x + tetra->hash[0].x] = tetra->c;
	greed[y + tetra->hash[1].y][x + tetra->hash[1].x] = tetra->c;
	greed[y + tetra->hash[2].y][x + tetra->hash[2].x] = tetra->c;
	greed[y + tetra->hash[3].y][x + tetra->hash[3].x] = tetra->c;
	return (greed);
}

char	**ft_remove_tetra(t_tetro *tetra, char **greed, int x, int y)
{
	greed[y + tetra->hash[0].y][x + tetra->hash[0].x] = '.';
	greed[y + tetra->hash[1].y][x + tetra->hash[1].x] = '.';
	greed[y + tetra->hash[2].y][x + tetra->hash[2].x] = '.';
	greed[y + tetra->hash[3].y][x + tetra->hash[3].x] = '.';
	return (greed);
}

int		ft_roundup_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
	{
		i++;
	}
	return (i);
}
