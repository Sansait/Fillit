/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:44:43 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/19 04:19:19 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//	ft_putstr("\n\t<============= HERE CLEAN =============>\n");
	exit(-1);
}

void	ft_exit_usage(void)
{
	ft_putstr(MSG_USAGE);
	exit(-1);
}

int		tile_ishash(char c)
{
	return (c == '#') ? 1 : 0;
}

int		tile_notvalid(char c)
{
	return (c == '.' || c == '#') ? 0 : 1;
}
