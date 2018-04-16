/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 19:42:39 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_parse(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes;
	char	*str;
	t_list	tetra;

	bytes = read(fd, buff, BUFF_SIZE);
	ASSERT(bytes % 21 != 20);
	buff[bytes] = '\0';
	ft_fastcheck(buff, ((bytes / 21) + 1));
	tetra = ft_slowcheck(buff, ((bytes / 21) + 1));
	return (tetra);
}
