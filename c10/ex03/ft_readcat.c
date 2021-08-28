/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:32:26 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 11:27:09 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static void	ft_expand_string(t_file *f, uint8_t *buffer, int rd)
{
	uint8_t	*new_str;

	new_str = malloc(f->len + rd);
	if (!new_str)
	{
		free(f->f);
		return ;
	}
	ft_memcpy(new_str, f->f, f->len);
	ft_memcpy(&new_str[f->len], buffer, rd);
	f->len += rd;
	free(f->f);
	f->f = new_str;
}

int	fetch_file(t_file *f, int fd)
{
	uint8_t	buf[4096];
	int		rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, 4096);
		if (rd > 0)
		{
			ft_expand_string(f, buf, rd);
			if (!f->f)
				return (0);
		}
		if (rd < 0)
			return (errno);
	}
	return (0);
}
