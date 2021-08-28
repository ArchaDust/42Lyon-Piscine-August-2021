/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:58:11 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/25 10:51:22 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_c(char c)
{
	write(1, &c, 1);
}

int	is_bsq(int x, int y, t_bsq *b)
{
	if (x >= b->x && x < b->x + b->sqr)
	{
		if (y >= b->y && y < b->y + b->sqr)
			return (1);
	}
	return (0);
}

void	ft_print_bsq(t_map *m)
{
	int	x;
	int	y;
	int	offset;

	y = 0;
	while (y < m->h)
	{
		x = 0;
		offset = 0;
		while (x < m->w)
		{
			if (is_bsq(x, y, &m->bsq))
				ft_print_c(m->fill);
			else if (x == m->map[y][offset])
			{
				ft_print_c(m->obstacle);
				offset++;
			}
			else
				ft_print_c(m->empty);
			x++;
		}
		ft_print_c('\n');
		y++;
	}
}
