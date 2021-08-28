/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:00:09 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 16:42:39 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
			|| c == '\r' || c == '\v' || c == '\f');
}

char	*ft_get_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ':' && !ft_is_ws(str[i]))
		i++;
	key = malloc(i + 1);
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != ':' && !ft_is_ws(str[i]))
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

static int	ft_get_value_size(char *str)
{
	int		last;
	int		in_word;
	int		i;

	i = 0;
	last = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_ws(str[i] && !in_word))
			in_word = 1;
		if (ft_is_ws(str[i]) && in_word)
		{
			in_word = 0;
			last = i;
		}
		i++;
	}
	if (in_word)
		last = i;
	return (last);
}

char	*ft_get_value(char *str)
{
	char	*value;
	int		i;
	int		size;

	i = 0;
	size = ft_get_value_size(str);
	value = malloc(size + 1);
	if (!value)
		return (NULL);
	i = 0;
	while (i < size)
	{
		value[i] = str[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}
