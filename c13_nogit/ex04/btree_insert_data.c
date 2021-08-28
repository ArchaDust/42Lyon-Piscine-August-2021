/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:14:04 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 13:20:58 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **r, void *i, int (*cmpf)(void *, void *))
{
	if (!r || !cmpf)
		return ;
	if (!(*r))
	{
		*r = btree_create_node(i);
		return ;
	}
	if ((*cmpf)((*r)->item, i) < 0)
		btree_insert_data(&((*r)->left), i, cmpf);
	else
		btree_insert_data(&((*r)->right), i, cmpf);
}
