/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:37:56 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/11 13:27:46 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// 46341 respresents the limit at which we can get a sqr within INT_MAX range

int	ft_sqrt(int nb)
{
	int	count;
	int	tmp;

	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	count = 1;
	while (count < 46341)
	{
		tmp = count * count;
		if (tmp > nb)
			return (0);
		if (tmp == nb)
			return (count);
		count++;
	}
	return (0);
}
