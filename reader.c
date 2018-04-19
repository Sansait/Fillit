/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/19 11:26:27 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Verify that the format of the map is OK.
** Check all the '/n' (aka the format of the data).
*/

static	void	ft_fastcheck(char *data, int tetro_count)
{
	if (DEBUG)
		print_int("\ntetro_count :", tetro_count);
	while (tetro_count--)
	{
		if (data[4] != '\n' || data[9] != '\n' || data[14] != '\n' \
			|| data[19] != '\n')
			ft_exit_error();
		if (tetro_count)
		{
			if (data[20] != '\n')
				ft_exit_error();
			data += 21;
		}
	}
}

/*
** Parse one data block.										<-alloc memory.
** Built a data set from the map string.
** return a group of 4 points.
** toby[0] = line		(y)
** toby[1] = colomns	(x)
** toby[2] = hash count
*/

static	t_point	*ft_parse_oneblock(char *data)
{
	t_point	*pos_set;
	int		toby[3];

	ft_bzero(toby, 3 * sizeof(int));
	if (!(pos_set = ft_memalloc(4 * sizeof(t_point))))
		ft_exit_clean();
	while (toby[0] < 4)
	{
		toby[1] = 0;
		while (toby[1] < 4)
		{
			if (tile_notvalid(data[(5 * toby[0]) + toby[1]]))
				ft_exit_clean();
			if (tile_ishash(data[(5 * toby[0]) + toby[1]]))
			{
				if (toby[2] == 4)
					ft_exit_clean();
				pos_set[toby[2]] = built_point(toby[1], toby[0]);
				toby[2]++;
			}
			toby[1]++;
		}
		toby[0]++;
	}
	return (pos_set);
}

/*
** verify that the pos_set is gud.								<-alloc memory.
** count the link count and make sure it above 6.
** call set the node for final tweaks.
** return a pointer on the tetros.
*/

static	t_tetro	what_tetro(t_point pos_set[4], char c)
{
	t_tetro	*node;
	int		link_count;
	int		i;

	link_count = 0;
	i = -1;
	if (DEBUG)
		print_pos_set(pos_set);
	if (!(node = ft_memalloc(sizeof(t_tetro))))
		ft_exit_clean();
	while (++i < 4)
		link_count += check_links(i, pos_set);
	if (DEBUG)
		print_int("link_count : ", link_count);
	if (link_count < 6)
		ft_exit_clean();
	ft_memcpy(node->hash, pos_set, 4 * sizeof(t_point));
	set_tetro(&node);
	node->c = c;
	return (*node);
}

/*
** Make the data list with all the tetros.
** Verify that the charset of the map is OK & call the parcer.
** ft_parse_oneblock trigger error.
** return a t_list containing the tetros.
*/

static	t_list	ft_slowcheck(char *data, int tetro_count)
{
	t_list	*res;
	t_point	cood[4];
	t_tetro	node;
	char	c;

	c = 'A';
	res = NULL;
	while (tetro_count--)
	{
		ft_memcpy(cood, ft_parse_oneblock(data), 4 * sizeof(t_point));
		data += 20;
		if (tetro_count > 0)
			data++;
		node = what_tetro(cood, c++);
		ft_lstadd(&res, ft_lstnew(&node, sizeof(node)));
	}
	ft_lstrev(&res);
	return (*res);
}

/*
** Read from the file and check the line count.
** Fetch the data from the open file.
*/

t_list			ft_parse(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes;
	t_list	tetra;

	bytes = read(fd, buff, BUFF_SIZE);
	if (DEBUG)
		print_int("\nBytes read ;", bytes);
	if (bytes % 21 != 20)
		ft_exit_error();
	buff[bytes] = '\0';
	ft_fastcheck(buff, ((bytes / 21) + 1));
	tetra = ft_slowcheck(buff, ((bytes / 21) + 1));
	if (DEBUG)
		ft_putstr("\n\t<============ PARSING DONE ============>\n");
	if (DEBUG)
		print_lst_tetro(&tetra);
	return (tetra);
}
