/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:06:18 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 11:32:53 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*tmp;

	if (!begin_list)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	i = 0;
	tmp = begin_list;
	while (tmp != NULL)
	{
		if (i == nbr)
			return (tmp);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
