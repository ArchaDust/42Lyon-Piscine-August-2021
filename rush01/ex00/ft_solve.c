/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:06:20 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 21:34:53 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boxes.h"

int	ft_verif_depth(t_board *board, int depth)
{
	int		y;
	int		x;
	int		l;

	y = 0;
	l = board->length;
	while (y < depth)
	{
		x = 0;
		while (x < l)
		{
			if (board->cell[l * y + x] == board->cell[depth * l + x])
				return (0);
			x++;
		}
		y++;
	}
	if (ft_valid_left(board, depth) && ft_valid_right(board, depth))
		return (ft_solve(board, depth + 1));
	return (0);
}

static void	ft_fetch_lookup(t_board *board, t_byte *data, int depth, int i)
{
	int		x;

	x = 0;
	while (x < board->length)
	{
		board->cell[x + depth * board->length] = data[i * board->length + x];
		x++;
	}
}

int	ft_solve(t_board *board, int depth)
{
	int		i;

	i = 0;
	if (depth >= board->length)
	{
		while (i < board->length)
		{
			if (!(ft_valid_up(board, i) && ft_valid_down(board, i)))
				return (0);
			i++;
		}
		return (1);
	}
	i = 0;
	while (i < board->look.fact)
	{
		ft_fetch_lookup(board, board->look.data, depth, i);
		if (ft_verif_depth(board, depth))
			return (1);
		i++;
	}
	return (0);
}
