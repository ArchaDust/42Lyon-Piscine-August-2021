/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:34:13 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/11 17:52:53 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_queens(int *queens)
{
	int				i;
	int				c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static int	ft_menacing(int *queens, int row)
{
	int				i;

	i = 0;
	while (i < row)
	{
		if (queens[i] == queens[row])
			return (1);
		if (ft_abs(i - row) == ft_abs(queens[i] - queens[row]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_solve(int *queens, int n)
{
	if (n >= 10)
	{
		queens[10]++;
		ft_print_queens(queens);
		return (0);
	}
	queens[n] = 0;
	while (queens[n] < 10)
	{
		if (!ft_menacing(queens, n) && ft_solve(queens, n + 1))
			return (1);
		queens[n]++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int				queens[11];
	int				i;

	i = 0;
	while (i < 11)
		queens[i++] = 0;
	ft_solve(queens, 0);
	return (queens[10]);
}
