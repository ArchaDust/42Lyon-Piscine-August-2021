/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:21:49 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 16:18:02 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static char	*ft_expand_string(char *src, char *buffer)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(src) + ft_strlen(buffer);
	new_str = malloc(size + 1);
	if (!new_str)
	{
		free(src);
		return (NULL);
	}
	new_str[0] = '\0';
	ft_strcat(new_str, src);
	ft_strcat(new_str, buffer);
	free(src);
	return (new_str);
}

static char	*ft_fileread(int fd)
{
	char	buffer[4096 + 1];
	int		rd;
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, 4096);
		if (rd < 0)
			return (str);
		buffer[rd] = '\0';
		if (rd > 0)
			str = ft_expand_string(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_full_read(char *file_name)
{
	int		fd;
	char	*str;

	fd = open(file_name, 0);
	if (fd < 0)
		return (NULL);
	str = ft_fileread(fd);
	close(fd);
	return (str);
}

char	*ft_full_stdin_read(char **key)
{
	*key = ft_fileread(0);
	return (ft_full_read("numbers.dict"));
}
