/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 13:16:12 by lgeniaux          #+#    #+#             */
/*   Updated: 2021/08/22 16:41:14 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char	*rev_str(char *str)
{
	int		i;
	int		j;
	int		len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

static int	ft_get_num_len(int nb)
{
	int		size;
	int		temp;

	temp = nb;
	size = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		size++;
	}
	if (nb == 0)
		size = 1;
	return (size);
}

char	*ft_itoa(int nb)
{
	int		size;
	int		temp;
	char	*str;
	int		i;

	i = 0;
	temp = nb;
	size = ft_get_num_len(nb);
	str = malloc(sizeof(char) * (size + 1));
	if (!(str))
		return (NULL);
	while (i < size)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	return (rev_str(str));
}
