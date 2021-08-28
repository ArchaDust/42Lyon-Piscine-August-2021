/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:38:57 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/20 14:25:09 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

static int	ft_get_op(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '*')
		return (2);
	if (op == '/')
		return (3);
	if (op == '%')
		return (4);
	return (-1);
}

static int	ft_check_op_error(char *op)
{
	if (op[0] == '\0')
		return (-1);
	if (op[1] != '\0')
		return (-1);
	return (0);
}

static void	ft_do_op(int a, int b, char *op)
{
	void	(*p[5])(int, int);
	int		op_id;

	p[0] = ft_plus;
	p[1] = ft_minus;
	p[2] = ft_mult;
	p[3] = ft_div;
	p[4] = ft_mod;
	if (ft_check_op_error(op) < 0)
	{
		ft_putstr("0\n");
		return ;
	}
	op_id = ft_get_op(*op);
	if (op_id < 0)
	{
		ft_putstr("0\n");
		return ;
	}
	(*(p[op_id]))(a, b);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	ft_do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2]);
	return (0);
}
