/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:25:44 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 23:50:14 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check all the '/n', check the format of the data.
*/

void	ft_fastcheck(char *data, int tetro_count)
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

t_tetro			ft_built_tetro(char **data)
{
	t_tetro	node;


	data += 20;
	return (node);
}

/*
** Make the data list with all the tetros. 
*/

t_list	ft_slowcheck(char *data, int tetro_count)
{
	t_list	*res;
	t_tetro	node;

	t_list = NULL;
	while (tetro_count--)
	{
		node = ft_built_tetro(&data);
		ft_lstadd(&res, ft_lstnew(&node, sizeof(node)));
	}
	return (res);
}
