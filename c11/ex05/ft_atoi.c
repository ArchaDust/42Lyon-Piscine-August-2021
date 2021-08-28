/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:19:30 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/20 12:34:50 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

static int	ft_is_wspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_trim(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' || ft_is_num(str[i]))
			return (i);
		if (!ft_is_wspace(str[i]))
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_managesigns(char *str, int *i)
{
	int	negative;

	negative = 1;
	while (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '+' || \
				ft_is_num(str[*i])))
	{
		if (ft_is_num(str[*i]))
			return (negative);
		if (str[*i] == '-')
			negative = -negative;
		(*i)++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	negative;

	if (!str)
		return (0);
	i = ft_trim(str);
	if (i < 0 || str[i] == '\0')
		return (0);
	negative = ft_managesigns(str, &i);
	if (negative == 0)
		return (0);
	result = 0;
	while (str[i] != '\0' && ft_is_num(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * negative);
}
