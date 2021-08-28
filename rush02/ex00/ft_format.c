/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:50:39 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 22:50:39 by lgeniaux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <string.h>

char	*find_key(t_dict *dict, char *key)
{
	int	line;

	line = 0;
	while (dict[line].key != NULL && (strcmp(key, dict[line].key)) != 0)
	{
		line++;
	}
	return (dict[line].value);
}
