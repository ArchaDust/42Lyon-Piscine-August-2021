/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:07:37 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/05 03:10:09 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (*str == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_is_lower(str[i]))
			return (0);
		i++;
	}
	return (1);
}
