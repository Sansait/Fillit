/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:38:00 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/18 18:38:02 by nihuynh          ###   ########.fr       */
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

int 	check_links(t_point target, t_point pos_set[4])
{
	int i;
	int link_count;

	i = 0;
	link_count = 0;
	while (i++ < 4)
	{
		if (target.x == pos_set[i].x && target.y == pos_set[i].y + 1)
			link_count++;
		if (target.x == pos_set[i].x && target.y == pos_set[i].y - 1)
			link_count++;
		if (target.y == pos_set[i].y && target.x == pos_set[i].x + 1)
			link_count++;
		if (target.y == pos_set[i].y && target.x == pos_set[i].x - 1)
			link_count++;
	}
	return (link_count);
}

void 	set_tetro(t_tetro **pnode)
{
	int i;
	int xoffset;
	int yoffset;
	int width;
	int length;

	i = 0;
	xoffset = 4;
	yoffset = 4;
	width = 0;
	length = 0;
	while (i++ < 4)
	{
		xoffset = ft_min(xoffset, (*pnode)->hash[i].x);
		yoffset = ft_min(yoffset, (*pnode)->hash[i].y);
		width	= ft_max(width, (*pnode)->hash[i].x);	
		length	= ft_max(length, (*pnode)->hash[i].y);
	}
	while (i++ < 4)
	{
		(*pnode)->hash[i].x -= xoffset;
		(*pnode)->hash[i].y -= yoffset;
	}
	(*pnode)->width = width - xoffset;
	(*pnode)->length = length - yoffset;
}
