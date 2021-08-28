/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:07:34 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/18 10:34:01 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// 46341 respresents the limit at which we can get a sqr within INT_MAX range
// This version of ft_sqrt is different than the one from ex05
// It will return the trucated integer sqr of nb

static int	ft_sqrt(int nb)
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
		if (tmp >= nb)
			return (count);
		count++;
	}
	return (count);
}

static int	ft_is_prime(int nb)
{
	int	i;
	int	sqr_nb;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	sqr_nb = ft_sqrt(nb) + 1;
	while (i < sqr_nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	nb += 2;
	if (nb % 2 == 0)
		nb--;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}
