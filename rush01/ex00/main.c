/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:21:58 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 21:23:30 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boxes.h"

static void	ft_memset(void *addr, unsigned char value, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (!addr)
		return ;
	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ptr[i] = value;
		i++;
	}
}

static int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_board			board;
	int				length;

	if (argc != 2)
		return (ft_error());
	ft_memset(&board, 0, sizeof(t_board));
	length = ft_get_input_length(argv[1]);
	if (length < 3)
		return (ft_error());
	if (ft_check_input(argv[1], length))
		return (ft_error());
	if (ft_init_board(&board, length) < 1)
		return (ft_error());
	ft_get_input_data(&board, argv[1]);
	ft_memset(board.cell, 0, length * length * sizeof(t_byte));
	if (ft_solve(&board, 0) < 1)
	{
		ft_delete_board(&board);
		return (ft_error());
	}
	ft_display_board(&board);
	ft_delete_board(&board);
	return (0);
}
