/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:44:34 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 10:48:56 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*tmp;
	t_list	*current;
	int		i;

	if (!size || !strs)
		return (NULL);
	tmp = NULL;
	i = 0;;
	while (i < size)
	{
		current = ft_create_elem(strs[i]);
		if (!current)
			return (tmp);
		current->next = tmp;
		tmp = current;
	}
	return (tmp);
}
