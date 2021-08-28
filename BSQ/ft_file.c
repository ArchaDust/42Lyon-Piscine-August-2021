/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:26:55 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/25 13:06:41 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_is_nonprint(char c)
{
	if (c <= ' ' || c >= 127)
		return (1);
	return (0);
}

static int	ft_extract_header(t_map_parse *m, char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0' && (buffer[i] >= '0' && buffer[i] <= '9'))
		m->h = m->h * 10 + (buffer[i++] - '0');
	if (buffer[i] == '\0' || buffer[i] == '\n' || ft_is_nonprint(buffer[i]))
		return (-1);
	m->empty = buffer[i++];
	if (buffer[i] == '\0' || buffer[i] == '\n' || ft_is_nonprint(buffer[i]))
		return (-2);
	m->obstacle = buffer[i++];
	if (buffer[i] == '\0' || buffer[i] == '\n' || ft_is_nonprint(buffer[i]))
		return (-3);
	m->fill = buffer[i++];
	if (buffer[i] != '\n')
		return (-4);
	i++;
	return (i);
}

static int	ft_next_line(t_map_parse *m)
{
	if (m->y == 0)
		m->w = m->x;
	if (m->x != m->w)
		return (-1);
	if (m->x != m->w)
		m->err_flag = 1;
	m->x = 0;
	if (m->y < m->h)
	{
		ft_push_to_line(&m->line, -1);
		m->map[m->y] = m->line.line;
		ft_prep_line(&m->line);
	}
	m->y++;
	if (m->y > m->h)
		return (-1);
	m->x = 0;
	return (0);
}

static int	ft_extract_data(t_map_parse *m, char *buffer, int rd)
{
	int			i;

	i = 0;
	while (i < rd)
	{
		if (buffer[i] == '\n')
		{
			if (ft_next_line(m) < 0)
				return (-10);
		}
		else if (buffer[i] == m->obstacle)
		{
			ft_push_to_line(&m->line, m->x);
			m->x++;
		}
		else if (buffer[i] == m->empty)
			m->x++;
		else
			return (-20);
		i++;
	}
	return (0);
}

int	read_file(t_map_parse *m, int fd)
{
	char		buffer[4096 + 1];
	int			rd;
	int			extract;

	rd = read(fd, buffer, 32);
	buffer[rd] = '\0';
	extract = ft_extract_header(m, buffer);
	if (extract < 0)
		return (-1);
	m->map = malloc(sizeof(int *) * m->h);
	if (!m->map)
		return (-2);
	ft_prep_line(&m->line);
	ft_strcpy(buffer, &buffer[extract]);
	rd -= extract;
	while (rd > 0)
	{
		if (ft_extract_data(m, buffer, rd) < 0)
			return (-1);
		rd = read(fd, buffer, 4096);
		if (rd >= 0)
			buffer[rd] = '\0';
	}
	return (0);
}
