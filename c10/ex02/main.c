/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:39:47 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 11:11:01 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static int	ft_fetch_stdin(int c)
{
	t_file	file;

	file.len = 0;
	file.f = NULL;
	fetch_file(&file, 0);
	if (!file.f)
		return (0);
	ft_tail(&file, c);
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

static int	ft_get_arg(char *a, char *b)
{
	int		c;

	if (ft_strcmp(a, "-c") != 0)
		return (-1);
	c = ft_atoi(b);
	if (c < 0)
		return (-1);
	return (c);
}

static void	ft_do_all_file(int ac, char **av, int n)
{
	t_file	file;
	int		i;
	int		fd;

	i = 3;
	while (i < ac)
	{
		fd = open(av[i], 0);
		if (fd < 0)
		{
			ft_err(errno, av[0], av[i]);
			i++;
			continue ;
		}
		file.len = 0;
		file.f = NULL;
		fetch_file(&file, fd);
		close(fd);
		ft_print_filenames(av[i], (ac > 4));
		ft_tail(&file, n);
		if (i < ac - 1 && ac > 4)
			write(1, "\n", 1);
		free(file.f);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		n;

	if (argc < 3)
		return (0);
	errno = 0;
	n = ft_get_arg(argv[1], argv[2]);
	if (n < 0)
		return (errno);
	if (argc == 3)
		return (ft_fetch_stdin(n));
	ft_do_all_file(argc, argv, n);
	return (errno);
}
