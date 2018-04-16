/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:02:21 by sklepper          #+#    #+#             */
/*   Updated: 2018/04/16 15:50:59 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list *new;
	t_list *tmp;

	tmp = *begin_list;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	new = ft_lstlast(*begin_list);
	while (tmp != tmp->next->next)
	{
		while (tmp->next->next != NULL && tmp->next != tmp->next->next->next)
			tmp = tmp->next;
		tmp->next->next = tmp;
		tmp = *begin_list;
	}
	tmp->next = NULL;
	*begin_list = new;
}
