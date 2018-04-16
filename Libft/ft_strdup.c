/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:29:33 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t		nb_char;
	size_t		i;
	char		*dest;

	nb_char = (size_t)ft_strlen(src);
	if (!(dest = ft_strnew(nb_char)))
		return (0);
	i = 0;
	while (i < nb_char)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
