/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 13:18:41 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 13:53:10 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*nl_beg;
	t_list	*it;

	if (!begin_list)
		return ;
	it = *begin_list;
	nl_beg = NULL;
	while (it->next != NULL)
	{
		tmp = it->next;
		it->next = ln_beg;
		it = tmp;
	}
	*begin_list = nl_beg;
}
