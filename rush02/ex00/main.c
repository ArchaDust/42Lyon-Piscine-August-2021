/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:35:52 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 23:21:40 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

static int	ft_dicterror(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

static void	ft_init_catreg(t_cat_reg *reg)
{
	reg->valid = 0;
	reg->data = malloc(1);
	if (!reg->data)
		return ;
	reg->data[0] = '\0';
	reg->valid = 1;
}

static int	ft_call_start(int argc, char **argv)
{
	t_cat_reg	reg;
	int			res;

	ft_init_catreg(&reg);
	if (argc == 2)
		res = ft_start_dict("numbers.dict", argv[1], 0, &reg);
	else if (argc == 3)
		res = ft_start_dict(argv[1], argv[2], 0, &reg);
	else
		res = ft_start_dict(NULL, NULL, 1, &reg);
	if (res > 0)
		return (ft_error());
	if (reg.valid)
	{
		ft_putstr(reg.data);
		ft_putstr("\n");
	}
	else
		return (ft_dicterror());
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 1 || argc > 3)
		return (ft_error());
	ft_call_start(argc, argv);
	return (0);
}
