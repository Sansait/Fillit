/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:38:00 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/19 00:40:10 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_point	built_point(int x, int y)
{
	t_point res;

	res.x = x;
	res.y = y;
	return (res);
}

int		check_links(int select, t_point set[4])
{
	int i;
	int link_count;

	i = -1;
	link_count = 0;
	while (++i < 4)
	{
		if (set[select].x == set[i].x && set[select].y == set[i].y + 1)
			link_count++;
		if (set[select].x == set[i].x && set[select].y == set[i].y - 1)
			link_count++;
		if (set[select].y == set[i].y && set[select].x == set[i].x + 1)
			link_count++;
		if (set[select].y == set[i].y && set[select].x == set[i].x - 1)
			link_count++;
	}
	return (link_count);
}

void	set_tetro(t_tetro **pnode)
{
	int i;
	int xoffset;
	int yoffset;
	int toby[2];

	i = -1;
	xoffset = 4;
	yoffset = 4;
	ft_bzero(&toby, sizeof(toby));
	while (++i < 4)
	{
		xoffset = ft_min(xoffset, (*pnode)->hash[i].x);
		yoffset = ft_min(yoffset, (*pnode)->hash[i].y);
		toby[0] = ft_max(toby[0], (*pnode)->hash[i].x);
		toby[1] = ft_max(toby[1], (*pnode)->hash[i].y);
	}
	i = -1;
	while (++i < 4)
	{
		(*pnode)->hash[i].x -= xoffset;
		(*pnode)->hash[i].y -= yoffset;
	}
	(*pnode)->width = 1 +  toby[0] - xoffset;
	(*pnode)->length = 1 + toby[1] - yoffset;
}
