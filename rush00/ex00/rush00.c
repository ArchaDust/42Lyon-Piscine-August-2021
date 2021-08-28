/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 09:53:22 by mserrato          #+#    #+#             */
/*   Updated: 2021/08/08 10:17:31 by mserrato         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_pick_char(int a, int b, int x, int y)
{
	if (a == 0 && b == 0)
		return ('o');
	if (a == y - 1 && b == 0)
		return ('o');
	if (a == 0 && b == x - 1)
		return ('o');
	if (a == y - 1 && b == x - 1)
		return ('o');
	if ((a == 0 || a == y - 1) && (b != 0 && b != x - 1))
		return ('-');
	if ((b == 0 || b == x - 1) && (a != 0 && a != y - 1))
		return ('|');
	return (' ');
}

void	rush(int x, int y)
{
	int	a;
	int	b;

	if (x < 1 || y < 1)
		return ;
	a = 0;
	while (a < y)
	{
		b = 0;
		while (b < x)
		{
			ft_putchar(ft_pick_char(a, b, x, y));
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}
