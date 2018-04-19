/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:48:58 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/19 15:37:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int fd;
	t_list tetra;

	if (ac != 2)
		ft_exit_usage();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_exit_error();
//	if (DEBUG)
//		ft_putstr("\t<============== DEBUG ON ==============>\n");
	tetra = ft_parse(fd);
	ft_solver(tetra);
	return (0);
}
