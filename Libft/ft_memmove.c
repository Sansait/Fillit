/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:00:21 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*srcs;
	char	*dest;
	size_t	i;

	i = -1;
	srcs = (char *)src;
	dest = (char *)dst;
	if (srcs < dest)
		while ((int)(--n) >= 0)
			*(dest + n) = *(srcs + n);
	else
		while (++i < n)
			*(dest + i) = *(srcs + i);
	return (dst);
}
