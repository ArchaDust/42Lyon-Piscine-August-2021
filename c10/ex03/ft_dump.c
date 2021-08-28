/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:42:26 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 09:38:38 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static void	ft_dump_hexline(uint8_t *f, int line_len)
{
	int				i;

	i = 0;
	while (i < line_len)
	{
		write_hex(f[i]);
		if (i < 15)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i < 15)
			write(1, " ", 1);
		i++;
	}
}

static int	double_line_check(t_file *f, int *dbl, int i)
{
	if (*dbl < 0)
	{
		*dbl = 0;
		return (1);
	}
	if (ft_memcmp(&(f->f)[*dbl], &(f->f)[i], 16) == 0)
	{
		if (*dbl + 16 == i)
			write(1, "*\n", 2);
	}
	else
	{
		*dbl = i;
		return (1);
	}
	return (0);
}

void	ft_dump(t_file *f)
{
	size_t	i;
	int		line_len;
	int		dbl;

	if (!f->f || f->len < 1)
		return ;
	i = 0;
	dbl = -16;
	while (i < f->len)
	{
		line_len = f->len - i;
		if (line_len > 16)
			line_len = 16;
		if (double_line_check(f, &dbl, i))
		{
			write_offset(i, 1);
			ft_dump_hexline(&f->f[i], line_len);
			write(1, "\n", 1);
		}
		i += 16;
	}
	write_offset(f->len, 0);
}
