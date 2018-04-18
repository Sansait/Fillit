/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 19:42:39 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Verify that the format of the map is OK.
** Check all the '/n'aka (the format of the data).
*/

void		ft_fastcheck(char *data, int tetro_count)
{
	ssize_t len_data;

	len_data = ft_strlen(data);
	ASSERT(!len_data);
	while (tetro_count--)
	{
		ASSERT(data[4] != '\n' || data[9] != '\n' || \
				data[14] != '\n' || data [19] != '\n');
		if (tetro_count)
		{
			ASSERT(data[20] != '\n');
			data += 21;
		}
	}
}

/*
** Parse one data block.
** Built a data set from the map string.
** return a group of 4 points.
** toby[0] = line
** toby[1] = colomns
** toby[2] = offset
** toby[3] = hash count
*/

t_point		*ft_parse_oneblock(char **data)
{
	t_point	*pos_set;
	int		toby[4];

	ft_bzero(toby, 4 * sizeof(int));
	pos_set = ft_memalloc(4 * sizeof(t_point));
	while (toby[0] < 4)
	{
		toby[1] = 0;
		while (toby[1] < 4)
		{
			tile_isvalid(*data[(1 + toby[0]) * toby[1] + toby[2]]);
			if (tile_ishash(*data[(1 + toby[0]) * toby[1] + toby[2]]))
			{
				toby[3]++;
				if (toby[3] == 4)
					ft_exit_error();
				pos_set[toby[3]] = built_point(toby[0], toby[1]);
			}
			toby[1]++;
		}
		toby[2]++;
	}
	data += 20;
	return (pos_set);
}

/*
** verify that the pos_set is gud
** return a tetros struct
** TODO : nico
*/

t_tetro 	ft_witch_tetro(t_point	pos_set[4])
{
	t_tetro	*node;

	node = NULL;
	ft_bzero((void*)node, sizeof(node));
	ft_memcpy(node->hash, pos_set, 4 * sizeof(t_point));
	node->length = 1;
	node->width = 4;
	return (*node);
}

/*
** Make the data list with all the tetros.
** Verify that the charset of the map is OK & call the parcer.
*/

t_list		ft_slowcheck(char *data, int tetro_count)
{
	t_list	*res;
	t_point	cood[4];
	t_tetro	node;

	res = NULL;
	while (tetro_count--)
	{
		ft_memcpy(cood, ft_parse_oneblock(&data), 4 * sizeof(t_point));
		if (tetro_count > 0)
			data++;
		node = ft_witch_tetro(cood);
		ft_lstadd(&res, ft_lstnew(&node, sizeof(node)));
	}
	return (*res);
}

/*
** Read fron the file and check the line count.
** Fetch the data from the open file.
*/

t_list		ft_parse(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes;
	t_list	tetra;

	bytes = read(fd, buff, BUFF_SIZE);
	ASSERT(bytes % 21 != 20);
	buff[bytes] = '\0';
	ft_fastcheck(buff, ((bytes / 21) + 1));
	tetra = ft_slowcheck(buff, ((bytes / 21) + 1));
	return (tetra);
}