/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:46 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 13:33:10 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
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
