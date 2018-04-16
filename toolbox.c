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
#include <stdlib.h>

/*
** Handle the 2 types of output for the error.
*/

void	ft_exit_error(void)
{
	ft_putstr(MSG_ERROR);
	exit(-1);
}

void	ft_exit_usage(void)
{
	ft_putstr(MSG_USAGE);
	exit(-1);
}
