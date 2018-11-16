/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 23:20:20 by nihuynh           #+#    #+#             */
/*   Updated: 2018/04/23 10:17:45 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_exit_error(void)
{
	ft_putendl(MSG_ERROR);
	exit(0);
}

void	ft_exit_clean(void)
{
	ft_putendl(MSG_ERROR);
	exit(0);
}

void	ft_exit_usage(void)
{
	ft_putendl(MSG_USAGE);
	exit(0);
}

int		tile_ishash(char c)
{
	return (c == '#') ? 1 : 0;
}

int		tile_notvalid(char c)
{
	return (c == '.' || c == '#') ? 0 : 1;
}
