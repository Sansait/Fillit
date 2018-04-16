/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 17:25:23 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*reader(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes;
	char	*str;

	bytes = read(fd, buff, BUFF_SIZE);
	if (!bytes)
		exit (-1);
	if (bytes % 21 != 20)
		ft_error_exit();
	buff[bytes] = '\0';

	return (buff);
}