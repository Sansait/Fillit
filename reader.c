/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 16:59:43 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

char	*reader(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes;

	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{

	}
}