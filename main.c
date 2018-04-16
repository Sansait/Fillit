/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:48:58 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 17:46:00 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		ft_error_exit();
	if ((fd = open(av[1], O_RDONLY) == -1))
		ft_error_exit();
	ft_parse(fd);
	return (0);
}