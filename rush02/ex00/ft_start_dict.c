/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:41:57 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 23:17:42 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static void	ft_split_free(char **spl)
{
	int			i;

	i = 0;
	while (spl[i] != '\0')
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

static void	ft_free_dict(t_dict *dict)
{
	int			i;

	i = 0;
	while (dict[i].key != NULL)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

static t_dict	*ft_file_to_dict(char *str)
{
	char		**spl;
	t_dict		*dict;

	spl = ft_split(str, "\n");
	free(str);
	if (!spl)
		return (NULL);
	dict = ft_sanitize_input(spl);
	ft_split_free(spl);
	return (dict);
}

/*if (!ft_atoicheck(str))
 * {	
 * free(str);	
 * return (2);
 * }*/

int	ft_start_dict(char *file, char *input_key, int stdin_flag, t_cat_reg *reg)
{
	char		*str;
	t_dict		*dict;

	if (stdin_flag)
		str = ft_full_stdin_read(&input_key);
	else
		str = ft_full_read(file);
	if (!str)
		return (1);
	dict = ft_file_to_dict(str);
	ft_digit_split(dict, reg, input_key);
	ft_free_dict(dict);
	return (0);
}
