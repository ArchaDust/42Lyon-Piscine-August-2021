/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:21:36 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/18 20:18:54 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	size_t				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup(char *str)
{
	char				*res;
	size_t				size;
	size_t				i;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	ft_fastclear(struct s_stock_str *res, size_t count)
{
	size_t				i;

	i = 0;
	while (i < count)
	{
		if (res[i].copy)
			free(res[i].copy);
		res[i].copy = NULL;
		i++;
	}
}

static struct s_stock_str	ft_make_block(char *str)
{
	struct s_stock_str	res;

	res.size = ft_strlen(str);
	res.str = str;
	res.copy = ft_strdup(str);
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	size_t				i;

	if (ac < 0 || !av)
		return (NULL);
	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < sizeof(t_stock_str) * (ac + 1))
		((unsigned char *)res)[i++] = 0;
	i = 0;
	while (i < (size_t)ac)
	{
		res[i] = ft_make_block(av[i]);
		if (res[i].copy == NULL)
		{
			ft_fastclear(res, i);
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
