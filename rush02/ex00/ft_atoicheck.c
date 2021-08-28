/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoicheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:49:26 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 22:59:36 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static int	ft_is_wspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\r' || c == '\v' || c == '\f');
}

static int	ft_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoicheck(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0' && ft_is_wspace(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0' && ft_is_num(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
