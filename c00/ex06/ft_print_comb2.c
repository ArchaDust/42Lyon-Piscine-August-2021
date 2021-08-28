/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:15:04 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/04 13:03:03 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_ab(int a, int b)
{
	char	str[5];

	str[0] = ((a / 10) % 10) + '0';
	str[1] = (a % 10) + '0';
	str[2] = ' ';
	str[3] = ((b / 10) % 10) + '0';
	str[4] = (b % 10) + '0';
	write(1, str, 5);
	if (!(a == 98 && b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_print_ab(a, b);
			b++;
		}
		a++;
	}
}
