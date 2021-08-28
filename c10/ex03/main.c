/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:39:47 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 11:33:34 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static int	ft_fetch_stdin(int flag)
{
	t_file	file;

	file.len = 0;
	file.f = NULL;
	fetch_file(&file, 0);
	if (flag)
		ft_dumpc(&file);
	else
		ft_dump(&file);
	free(file.f);
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	if (*s1 == '\0' || *s2 == '\0')
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
	return (0);
}

static void	ft_dumpany(t_file *f, int flag)
{
	if (flag)
		ft_dumpc(f);
	else
		ft_dump(f);
	if (f->len > 0)
		write(1, "\n", 1);
}

static void	ft_do_all_file(int ac, char **av, int flag, int i_start)
{
	t_file	file;
	int		i;
	int		fd;

	i = i_start;
	file.len = 0;
	file.f = NULL;
	while (i < ac)
	{
		fd = open(av[i], 0);
		if (fd < 0)
			ft_err(errno, av[0], av[i]);
		if (fetch_file(&file, fd) != 0 && i == ac - 1)
			ft_err(errno, av[0], av[i]);
		close(fd);
		i++;
	}
	ft_dumpany(&file, flag);
	free(file.f);
}

int	main(int argc, char **argv)
{
	int		i;
	int		n;

	i = 2;
	errno = 0;
	if (argc < 2)
	{
		ft_fetch_stdin(0);
		return (errno);
	}
	n = (ft_strcmp(argv[1], "-C") == 0);
	if (n == 0 && argc < 2)
		return (ft_fetch_stdin(1));
	else
		ft_do_all_file(argc, argv, n, 1 + n);
	return (errno);
}
