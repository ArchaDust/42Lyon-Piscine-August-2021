/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:43:39 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 23:25:14 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	if_hundreds(char *group, t_dict *dict, t_cat_reg *reg, int i)
{
	int		nb;
	char	*tmp;

	nb = group[i] - 48;
	tmp = ft_itoa(nb);
	if (!tmp)
	{
		ft_register(reg, NULL);
		return ;
	}
	ft_register(reg, find_key(dict, tmp));
	ft_register(reg, find_key(dict, "100"));
	free(tmp);
}

void	if_tens(char *group, t_dict *dict, t_cat_reg *reg, int i)
{
	int		nb;
	char	*tmp;

	nb = group[i] - 48;
	nb = nb * 10;
	if (nb == 10)
	{
		nb = nb + (group[i + 1] - 48);
	}
	tmp = ft_itoa(nb);
	if (!tmp)
	{
		ft_register(reg, NULL);
		return ;
	}
	ft_register(reg, find_key(dict, tmp));
	free(tmp);
}

void	if_units(char *group, t_dict *dict, t_cat_reg *reg, int i)
{
	int		nb;
	char	*tmp;

	nb = group[i] - 48;
	tmp = ft_itoa(nb);
	if (!tmp)
	{
		ft_register(reg, NULL);
		return ;
	}
	ft_register(reg, find_key(dict, tmp));
	free(tmp);
}
