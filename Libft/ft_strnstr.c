/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:06:43 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	if (*s2 == '\0')
		return (char *)(s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0')
			j++;
		if ((size_t)(i + j) > n)
			return (NULL);
		else if (s2[j] == '\0')
			return (char*)(s1 + i);
		i++;
	}
	return (NULL);
}
