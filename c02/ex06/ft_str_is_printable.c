/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:12:15 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/07 07:07:10 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_print(unsigned char c)
{
	return ((c >= 0 && c <= 31) || c >= 127);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (*str == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (ft_is_print(str[i]))
			return (0);
		i++;
	}
	return (1);
}
