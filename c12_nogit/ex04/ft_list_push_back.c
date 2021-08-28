/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:41:07 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 10:43:19 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*to_add;
	t_list	*tmp;

	if (!begin_list)
		return ;
	to_add = ft_create_elem(data);
	if (!to_add)
		return ;
	tmp = *begin_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = to_add;
}
