/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:14:55 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, char c)
{
	int i;
	int nbr_words;

	nbr_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			nbr_words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (nbr_words);
}

char			**ft_strsplit(char const *s, char c)
{
	int				nbr_words;
	char			**dst;
	size_t			i;
	unsigned int	start;
	int				k;

	if (!s)
		return (NULL);
	nbr_words = ft_count_words(s, c);
	if ((dst = malloc(sizeof(char*) * (nbr_words + 1))) == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < nbr_words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		dst[k] = ft_strsub(s, start, i - start);
		k++;
	}
	dst[k] = 0;
	return (dst);
}
