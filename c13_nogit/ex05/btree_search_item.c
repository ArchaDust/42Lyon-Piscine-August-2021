/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:21:35 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 13:28:41 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *r, void *dr, int (*cmpf)(void *, void *))
{
	t_btree	*res;

	if (!r || !cmpf)
		return (NULL);
	res = NULL;
	res = btree_search_item(r->left, dr, cmpf);
	if (res)
		return (res);
	if ((*cmpf)(r->item, dr) == 0)
		return (r);
	return (btree_search_item(r->left, dr, cmpf));
}
