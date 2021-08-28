/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:15:26 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/25 13:15:57 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	ft_algo(t_map_parse *p)
{
	t_map	m;

	ft_memset(&m, 0, sizeof(t_map));
	m.w = p->w;
	m.h = p->h;
	m.map = p->map;
	m.obstacle = p->obstacle;
	m.fill = p->fill;
	m.empty = p->empty;
	if (m.fill == m.empty || m.fill == m.obstacle || m.obstacle == m.empty \
			|| p->h != p->y)
	{
		free(m.map);
		write(2, "map error\n", 10);
		return ;
	}
	ft_square(&m);
	ft_print_bsq(&m);
	free(m.map);
}

static void	ft_bsq_stdin(void)
{
	t_map_parse	map;
	int			val;

	ft_memset(&map, 0, sizeof(t_map_parse));
	val = read_file(&map, 0);
	if (val < 0)
		write(2, "map error\n", 10);
	else
		ft_algo(&map);
}

static void	ft_bsq_args(int ac, char **av)
{
	t_map_parse	map;
	int			i;
	int			fd;
	int			val;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], 0);
		if (fd >= 0)
		{
			ft_memset(&map, 0, sizeof(t_map_parse));
			val = read_file(&map, fd);
			if (val < 0)
				write(2, "map error\n", 10);
			else
				ft_algo(&map);
			close(fd);
		}
		else
			write(2, "map error\n", 10);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		ft_bsq_stdin();
	else
		ft_bsq_args(argc, argv);
	return (0);
}
