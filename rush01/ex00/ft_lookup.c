/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:57:50 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 21:35:04 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boxes.h"

static void	ft_push(t_lookup *look, t_byte *gen, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		look->data[look->filled] = gen[i];
		look->filled++;
		i++;
	}
}

static void	ft_swap(t_byte *a, t_byte *b)
{
	unsigned char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_all_permut(t_lookup *look, t_byte *gen, int length, int size)
{
	int		i;

	if (length < 1)
	{
		ft_push(look, gen, size);
		return (0);
	}
	i = 0;
	while (i < length)
	{
		ft_all_permut(look, gen, length - 1, size);
		if (length % 2 == 1)
			ft_swap(&gen[0], &gen[length - 1]);
		else
			ft_swap(&gen[i], &gen[length - 1]);
		i++;
	}
	return (0);
}

static int	ft_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

void	ft_generate_lookup(t_lookup *look, int size)
{
	t_byte	gen[9];
	int		i;

	i = 0;
	while (i < size)
	{
		gen[i] = i + 1;
		i++;
	}
	look->filled = 0;
	look->fact = ft_factorial(size);
	look->data = malloc(sizeof(t_byte) * size * look->fact);
	if (!look->data)
		return ;
	ft_all_permut(look, gen, size, size);
}
