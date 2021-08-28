/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:50:28 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/25 10:49:47 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_cell(t_map *m, int x, int y)
{
	int	i;

	i = 0;
	while (m->map[y][i] != -1)
	{
		if (m->map[y][i] >= x)
			return (m->map[y][i] == x);
		i++;
	}
	return (0);
}

int	get_cell_nextx(t_map *m, int x, int y)
{
	int	*ptr;
	int	i;

	ptr = m->map[y];
	i = 0;
	while (ptr[i] != -1)
	{
		if (ptr[i] >= x)
			return (ptr[i] - x);
		i++;
	}
	return (m->w - x);
}

int	get_cell_nexty(t_map *m, int x, int y)
{
	int	j;
	int	i;

	j = y;
	while (j < m->h)
	{
		i = 0;
		while (m->map[j][i] != -1 && m->map[j][i] < x)
			i++;
		if (m->map[j][i] == x)
			return (j);
		j++;
	}
	return (m->h - y);
}
