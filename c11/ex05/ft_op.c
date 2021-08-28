/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:31:11 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/20 14:26:08 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_plus(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	ft_minus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	ft_mult(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	ft_putnbr(a % b);
	write(1, "\n", 1);
}
