/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:49:15 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 10:52:50 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (!begin_list)
		return ;
	tmp = begin_list;
	while (tmp != NULL)
	{
		current = tmp;
		tmp = tmp->next;
		(*free_fct)(current->data);
		free(current);
	}
}
