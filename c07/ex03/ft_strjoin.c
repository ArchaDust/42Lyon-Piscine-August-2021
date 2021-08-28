/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:12:36 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/18 17:26:31 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static unsigned int	ft_strlens(char **strs, int size)
{
	int				ptr;
	int				total;

	ptr = 0;
	total = 0;
	while (ptr < size)
	{
		total += ft_strlen(strs[ptr]);
		ptr++;
	}
	return (total);
}

static char	*ft_strcat(char *dest, char *src)
{
	int				i;
	int				dlen;

	if (!dest || !src)
		return (dest);
	dlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dest);
}

static void	ft_apply_join(int size, char *str, char **strs, char *sep)
{
	int				ptr;

	ptr = 0;
	while (ptr < size - 1)
	{
		ft_strcat(str, strs[ptr]);
		ft_strcat(str, sep);
		ptr++;
	}
	ft_strcat(str, strs[ptr]);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*str;
	unsigned int	alloc_size;
	unsigned int	memset_counter;

	memset_counter = 0;
	if (!strs || size < 0)
		return (NULL);
	if (size == 0)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	alloc_size = ft_strlens(strs, size) + ft_strlen(sep) * (size - 1);
	str = malloc((alloc_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (memset_counter < alloc_size + 1)
		str[memset_counter++] = '\0';
	ft_apply_join(size, str, strs, sep);
	return (str);
}
