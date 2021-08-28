/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:04:06 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/25 10:50:03 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	ft_memcpy(uint8_t *addr, uint8_t *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		addr[i] = src[i];
		i++;
	}
}

void	ft_push_to_line(t_line *l, int x)
{
	int		*tmp;

	if (l->size == l->cap)
	{
		l->cap *= 2;
		if (l->cap > 100000)
			l->cap = 100001;
		tmp = malloc(l->cap * sizeof(int));
		if (!tmp)
			return ;
		ft_memcpy((uint8_t *)tmp, (uint8_t *)l->line, l->size * sizeof(int));
		free(l->line);
		l->line = tmp;
	}
	l->line[l->size] = x;
	l->size++;
}

int	ft_prep_line(t_line *l)
{
	l->cap = 1024;
	l->size = 0;
	l->line = malloc(l->cap * sizeof(int));
	if (!l->line)
		return (-1);
	return (1);
}
