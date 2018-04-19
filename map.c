/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:14:37 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/19 11:26:27 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_init_map(int sqr_size)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * sqr_size);
	i = 0;
	while (i < sqr_size)
	{
		map[i] = ft_memset(ft_strnew((size_t)sqr_size), '.', (size_t)sqr_size);
		i++;
	}
	return (map);
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
