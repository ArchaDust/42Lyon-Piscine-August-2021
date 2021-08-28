/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:56:32 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 21:08:30 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boxes.h"

void	ft_display_board(t_board *board)
{
	int		x;
	int		y;
	char	tmp;

	if (!board)
		return ;
	y = 0;
	while (y < board->length)
	{
		x = 0;
		while (x < board->length)
		{
			tmp = board->cell[x + y * board->length] + '0';
			write(1, &tmp, 1);
			if (x < board->length - 1)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_delete_board(t_board *board)
{
	if (!board)
		return ;
	if (board->cell)
		free(board->cell);
	if (board->border_up)
		free(board->border_up);
	if (board->border_down)
		free(board->border_down);
	if (board->border_left)
		free(board->border_left);
	if (board->border_right)
		free(board->border_right);
	board->length = -1;
}

int	ft_init_board(t_board *board, int length)
{
	if (!board || length < 4)
		return (0);
	ft_generate_lookup(&board->look, length);
	if (!board->look.data)
		return (0);
	board->cell = malloc(sizeof(t_byte) * length * length);
	board->border_up = malloc(sizeof(int) * length);
	board->border_down = malloc(sizeof(int) * length);
	board->border_left = malloc(sizeof(int) * length);
	board->border_right = malloc(sizeof(int) * length);
	if (!board->cell || !board->border_up || !board->border_down \
			|| !board->border_left || !board->border_right)
	{
		ft_delete_board(board);
		return (0);
	}
	board->length = length;
	return (1);
}
