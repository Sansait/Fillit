/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:25:44 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 17:32:37 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_exit(void)
{
	ft_putstr(MSG_ERROR);
	exit (-1);
}

//int		ft_fastcheck

//int		ft_slowcheck

