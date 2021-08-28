/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:33:49 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 10:36:47 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (!begin_list)
		return ;
	tmp = ft_create_elem(data);
	if (!tmp)
		return ;
	tmp->next = *begin_list;
	*begin_list = tmp;
}
