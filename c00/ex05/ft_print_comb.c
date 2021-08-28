/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:47:07 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/03 20:14:24 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_abc(int a, int b, int c)
{
	char	out[3];

	out[0] = (char)a + '0';
	out[1] = (char)b + '0';
	out[2] = (char)c + '0';
	write(1, out, 3);
	if (!(a == 7 && b == 8 && c == 9))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a < 8)
	{
		b = a + 1;
		while (b < 9)
		{
			c = b + 1;
			while (c < 10)
			{
				if (!(a == b || b == c || a == c))
					ft_print_abc(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
