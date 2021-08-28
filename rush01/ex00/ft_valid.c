/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:32:55 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 20:14:57 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boxes.h"

int	ft_valid_up(t_board *board, int pos)
{
	int	i;
	int	high;
	int	seen;
	int	tmp;

	seen = 0;
	high = 0;
	i = 0;
	if (pos >= board->length)
		return (0);
	while (i < board->length)
	{
		tmp = board->cell[pos + board->length * i];
		if (tmp > high)
		{
			high = tmp;
			seen++;
		}
		i++;
	}
	return (seen == board->border_up[pos]);
}

int	ft_valid_down(t_board *board, int pos)
{
	int	i;
	int	high;
	int	seen;
	int	tmp;

	seen = 0;
	high = 0;
	i = board->length - 1;
	if (pos >= board->length)
		return (0);
	while (i >= 0)
	{
		tmp = board->cell[pos + board->length * i];
		if (tmp > high)
		{
			high = tmp;
			seen++;
		}
		i--;
	}
	return (seen == board->border_down[pos]);
}

int	ft_valid_left(t_board *board, int pos)
{
	int	i;
	int	high;
	int	seen;
	int	tmp;

	seen = 0;
	high = 0;
	i = 0;
	if (pos >= board->length)
		return (0);
	while (i < board->length)
	{
		tmp = board->cell[pos * board->length + i];
		if (tmp > high)
		{
			high = tmp;
			seen++;
		}
		i++;
	}
	return (seen == board->border_left[pos]);
}

int	ft_valid_right(t_board *board, int pos)
{
	int	i;
	int	high;
	int	seen;
	int	tmp;

	seen = 0;
	high = 0;
	i = board->length - 1;
	if (pos >= board->length)
		return (0);
	while (i >= 0)
	{
		tmp = board->cell[pos * board->length + i];
		if (tmp > high)
		{
			high = tmp;
			seen++;
		}
		i--;
	}
	return (seen == board->border_right[pos]);
}
