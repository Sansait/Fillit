/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:44:43 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/17 00:44:47 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

void	ft_exit_error(void)
{
	ft_putstr(MSG_ERROR);
	exit(-1);
}

void	ft_exit_clean(void)
{
	ft_putstr(MSG_ERROR);
	exit(-1);
}

void	ft_exit_usage(void)
{
	ft_putstr(MSG_USAGE);
	exit(-1);
}

int		tile_ishash(char c)
{
	return (c == HASH) ? 1 : 0;
}

void	tile_isvalid(char c)
{
	if (c == TILE)
		return ;
	ft_exit_error();
}
