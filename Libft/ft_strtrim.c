/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:36:27 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strtrim2(char const *s, int i, size_t len, int k)
{
	char *new;

	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len)
	{
		new[k++] = s[i++];
		len--;
	}
	return (new);
}

static size_t	ft_newsize(char const *s)
{
	size_t start;
	size_t end;
	size_t i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	end = 0;
	while (s[i] != '\0')
	{
		while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
			i++;
		end = i;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
	}
	if (end == 0)
		return (0);
	return (end - start);
}

char			*ft_strtrim(char const *s)
{
	int			i;
	size_t		len;
	int			k;
	char		*new;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_newsize(s);
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	new = ft_strtrim2(s, i, len, k);
	if (new == NULL)
		return (NULL);
	return (new);
}
