/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:53:09 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 12:53:52 by lgeniaux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	ft_memset(void *mem, uint8_t val, size_t size)
{
	uint8_t	*ptr;
	size_t	i;

	ptr = (uint8_t *)mem;
	i = 0;
	while (i < size)
	{
		ptr[i] = val;
		i++;
	}
}
