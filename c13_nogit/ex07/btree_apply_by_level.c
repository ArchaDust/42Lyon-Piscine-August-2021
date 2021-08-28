/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:36:20 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 15:25:50 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	bt_level_count(t_btree *root)
{
	int	l;
	int	r;

	if (!root)
		return (0);
	l = btree_level_count(root->left);
	r = btree_level_count(root->right);
	if (l > r)
		return (l + 1);
	return (r + 1);
}

static void	nav(t_btree *r, int lvl, void (*af)(void *, int, int))
{
	(*af)(r->item, lvl, 0);
	nav(r->left, lvl + 1, af);
	nav(r->right, lvl + 1, af);
}

void	btree_apply_by_level(t_btree *r, void (*af)(void *, int, int))
{
	if (!r || !af)
		return ;
	(*af)(r->item, 0, 1);
	nav(r->left, 1, af);
	nav(r->right, 1, af);
}
