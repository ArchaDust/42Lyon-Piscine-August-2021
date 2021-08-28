/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitize_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:58:47 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 16:42:22 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static void	ft_to_dict(t_dict *dict, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ft_is_ws(str[i]))
		i++;
	dict->key = ft_get_key(&str[i]);
	while (str[i] != '\0' && str[i] != ':')
		i++;
	i++;
	while (str[i] != '\0' && ft_is_ws(str[i]))
		i++;
	dict->value = ft_get_value(&str[i]);
}

t_dict	*ft_sanitize_input(char **spl)
{
	int		i;
	int		size;
	t_dict	*dict;

	i = 0;
	size = 0;
	while (spl[size] != NULL)
		size++;
	dict = malloc((size + 1) * sizeof(t_dict));
	if (!dict)
		return (NULL);
	while (spl[i] != NULL)
	{
		ft_to_dict(&dict[i], spl[i]);
		i++;
	}
	dict[i].key = NULL;
	dict[i].value = NULL;
	return (dict);
}
