/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:39:47 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/19 10:49:20 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void	put_err(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

static void	print_file(int fd)
{
	char	buf[4096];
	int		rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, 4096);
		if (rd > 0)
			write(1, buf, rd);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		put_err("File name missing.\n");
		return (0);
	}
	else if (argc > 2)
	{
		put_err("Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], 0);
	if (fd < 0)
	{
		put_err("Cannot read file.\n");
		return (0);
	}
	print_file(fd);
	close(fd);
	return (0);
}
