/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_register.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:34:38 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 21:40:25 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static void	ft_reg_copy(t_cat_reg *reg, char *str, char *tmp, int size)
{
	if (reg->data[0] == '\0')
		ft_strcat(tmp, reg->data);
	else
	{
		ft_strcat(tmp, reg->data);
		tmp[size] = ' ';
	}
	tmp[size + 1] = '\0';
	ft_strcat(tmp, str);
	free(reg->data);
	reg->data = tmp;
}

void	ft_register(t_cat_reg *reg, char *str)
{
	int		i;
	int		size;
	char	*tmp;

	if (!reg->valid)
		return ;
	if (!str)
	{
		free(reg->data);
		reg->valid = 0;
		return ;
	}
	i = 0;
	size = ft_strlen(reg->data);
	tmp = malloc(size + ft_strlen(str) + 2);
	if (!tmp)
	{
		free(reg->data);
		reg->valid = 0;
		return ;
	}
	tmp[0] = '\0';
	ft_reg_copy(reg, str, tmp, size);
}
