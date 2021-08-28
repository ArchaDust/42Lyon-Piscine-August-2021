/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:24:02 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/25 12:57:11 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_square(t_map *m, int x, int y, int x_barrier)
{
	int	j;

	j = y;
	while (j < (x_barrier + y))
	{
		if (get_cell_nextx(m, x, j) < x_barrier)
			return (0);
		j++;
	}
	return (1);
}

void	ft_square2(t_map *m, int *x, int *y, int *x_barrier)
{
	int	tmp;

	*x_barrier = get_cell_nextx(m, *x, *y);
	tmp = get_cell_nexty(m, *x, *y);
	while (*x_barrier > m->bsq.sqr)
	{
		while (((*x_barrier + *y) > m->h) && *x_barrier > tmp)
			(*x_barrier)--;
		if (check_square(m, *x, *y, *x_barrier) == 1)
		{
			m->bsq.sqr = *x_barrier;
			m->bsq.x = *x;
			m->bsq.y = *y;
			return ;
		}
		(*x_barrier)--;
	}
}

void	ft_square(t_map *m)
{
	int	x;
	int	y;
	int	x_barrier;

	y = 0;
	while (y < m->h - m->bsq.sqr)
	{
		x = 0;
		while (x < m->w - m->bsq.sqr)
		{
			ft_square2(m, &x, &y, &x_barrier);
			x++;
		}
		y++;
	}
}
