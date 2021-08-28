/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 08:32:59 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/21 13:43:34 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dlen;

	if (!dest || !src)
		return (dest);
	dlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dest);
}
