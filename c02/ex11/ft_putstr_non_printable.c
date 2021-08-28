/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:18:50 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/07 07:11:08 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	ft_get_hex(unsigned char c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	return (c + 'a' - 10);
}

static void	ft_display_np_as_hex(unsigned char c)
{
	char	hi;
	char	lo;

	hi = ft_get_hex(c / 16);
	lo = ft_get_hex(c % 16);
	write(1, "\\", 1);
	write(1, &hi, 1);
	write(1, &lo, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
			ft_display_np_as_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
