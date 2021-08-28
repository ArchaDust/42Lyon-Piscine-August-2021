/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:34:45 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/11 11:24:24 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_cmp(char *hay, char *needle)
{
	int	i;

	i = 0;
	while (hay[i] == needle[i] && hay[i] != '\0')
		i++;
	if (needle[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (ft_cmp(&str[i], to_find))
			return (&str[i]);
		i++;
	}
	return ((void *)0);
}
