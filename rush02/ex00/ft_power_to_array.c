/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:12:24 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 22:51:09 by lgeniaux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"

char	*ft_power_to_array(int power)
{
	char	*array;
	int		i;

	i = 0;
	if (power > 1024)
		return (NULL);
	array = malloc(sizeof(char) * (power + 2));
	if (!(array))
		return (NULL);
	ft_memset(array, '0', (power + 2));
	array[0] = '1';
	array[power + 1] = '\0';
	return (array);
}
