/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:05:24 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 23:30:18 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	digit_to_reg(char *group, t_dict *dict, t_cat_reg *reg, int i)
{
	while (group[i])
	{
		if (i == 0 && group[i] != 0 && group[i] != '0')
		{
			if_hundreds(group, dict, reg, i);
		}
		if (i == 1 && group[i] != 0 && group[i] != '0')
		{
			if_tens(group, dict, reg, i);
		}
		if (i == 2 && group[i] != 0 && group[i] != '0' && group[i - 1] != '1')
		{
			if_units(group, dict, reg, i);
		}
		if (i == 2 && group[0] == '0' && group[1] == '0' && group[2] == '0')
		{
			if_units(group, dict, reg, i);
		}
		i++;
	}
}

void	array_fill(char *group, char *input, int *j, int *mod)
{
	int	i;

	i = 0;
	if ((*mod) != 0)
	{
		while (i < (3 - (*mod)))
			i++;
		(*mod) = 0;
	}
	while (input[*j] && i < 3)
	{
		group[i] = input[*j];
		(*j)++;
		i++;
	}
}

static void	ft_call_register(t_cat_reg *reg, t_dict *dict, int pow)
{
	char	*tmp;

	tmp = ft_power_to_array(pow);
	if (!tmp)
	{
		ft_register(reg, NULL);
		return ;
	}
	ft_register(reg, find_key(dict, tmp));
	free(tmp);
}

void	ft_digit_split(t_dict *dict, t_cat_reg *reg, char *input)
{
	int		i;
	int		j;
	int		mod;
	int		div;
	char	group[4];

	j = 0;
	mod = ft_strlen(input) % 3;
	div = ft_strlen(input) / 3;
	div += (mod != 0);
	while (input[j])
	{
		ft_memset(group, '0', 4);
		group[3] = '\0';
		i = 0;
		array_fill(group, input, &j, &mod);
		digit_to_reg(group, dict, reg, i);
		if (div != 0 && div != 1)
			ft_call_register(reg, dict, div * 3 - 3);
		if (mod == 0)
			div--;
		mod = 0;
	}
}
