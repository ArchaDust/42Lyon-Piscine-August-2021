/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:31:28 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/14 18:51:03 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print(char *str, int n)
{
	int		i;

	i = n - 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			if (str[0] >= '9' + 1 - (n - 1))
				return ;
		}
		else if (str[i - 1] >= str[i] || str[i] > '9')
			return ;
		i--;
	}
	write(1, str, n);
	if (!(str[0] >= '9' + 1 - n))
		write(1, ", ", 2);
}

static void	ft_loop(char *str, int step, int n)
{
	while (str[step] <= '9' + 1 - (n - step))
	{
		if (step < n - 1)
		{
			str[step + 1] = str[step] + 1;
			ft_loop(str, step + 1, n);
		}
		ft_print(str, n);
		str[step]++;
	}
}

void	ft_print_combn(int n)
{
	char	str[9];

	if (n < 1 || n >= 10)
		return ;
	str[0] = '0';
	ft_loop(str, 0, n);
}
