/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:00:33 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 17:03:02 by lgeniaux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power)
	{
		i *= nb;
		power--;
	}
	return (i);
}
