/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:17:58 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/10 22:22:02 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_alphanum(char c)
{
	int	boolean;

	boolean = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
	return (boolean || (c >= '0' && c <= '9'));
}

static char	ft_cap(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static int	ft_in_word(char *str, int i)
{
	while (ft_is_alphanum(str[i]))
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
		if (str[i] == '\0')
			return (i);
	}
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ((void *)0);
	while (str[i] != '\0')
	{
		if (ft_is_alphanum(str[i]))
		{
			str[i] = ft_cap(str[i]);
			i = ft_in_word(str, i + 1);
			if (str[i] == '\0')
				return (str);
		}
		i++;
	}
	return (str);
}
