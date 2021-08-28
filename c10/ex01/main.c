/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:39:47 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 11:17:03 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

static int	print_stdin(void)
{
	char	buf[4096];
	int		rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(0, buf, 4096);
		if (rd > 0)
			write(1, buf, rd);
		if (rd < 0)
			return (errno);
	}
	return (0);
}

static int	print_file(int fd)
{
	char	buf[4096];
	int		rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, 4096);
		if (rd > 0)
			write(1, buf, rd);
		if (rd < 0)
			return (errno);
	}
	return (0);
}

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_puterror(int errcode, char *pname, char *fname)
{
	int		i;
	int		p;
	int		f;
	char	*str;

	str = strerror(errcode);
	i = ft_strlen(str);
	p = ft_strlen(pname);
	f = ft_strlen(fname);
	write(2, pname, p);
	write(2, ": ", 2);
	write(2, fname, f);
	write(2, ": ", 2);
	write(2, str, i);
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	errno = 0;
	if (argc == 1)
		return (print_stdin());
	while (i < argc)
	{
		fd = open(argv[i], 0);
		if (fd < 0)
		{
			ft_puterror(errno, argv[0], argv[i]);
			i++;
			continue ;
		}
		if (print_file(fd) != 0)
			ft_puterror(errno, argv[0], argv[i]);
		close(fd);
		i++;
	}
	return (errno);
}
