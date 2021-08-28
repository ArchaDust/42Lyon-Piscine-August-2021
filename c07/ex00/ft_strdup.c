/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:24:15 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/08 16:56:20 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	unsigned int	i;
	char			*out;

	i = ft_strlen(str);
	out = malloc(i * sizeof(char) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
