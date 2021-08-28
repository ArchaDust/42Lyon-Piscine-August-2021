/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:12:05 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 09:13:04 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	write_readable_c(uint8_t *str, int len)
{
	int	i;

	i = 0;
	if (len < 0)
		return ;
	write(1, "|", 1);
	while (i < len)
	{
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "|", 1);
}

void	write_offset_c(uint32_t offset, int s)
{
	write_hex(offset / 16777216 % 256);
	write_hex(offset / 65536 % 256);
	write_hex(offset / 256 % 256);
	write_hex(offset % 256);
	if (s)
		write(1, "  ", 2);
}

// Without -C hexdump is kinda weird, I'm not gonna manage properly above 2^24

void	write_offset(uint32_t offset, int s)
{
	write(1, "0", 1);
	write_hex(offset / 65536 % 256);
	write_hex(offset / 256 % 256);
	write_hex(offset % 256);
	if (s)
		write(1, " ", 1);
}

void	write_hex(uint8_t c)
{
	const char	*hex_str;
	uint8_t		tmp[2];

	hex_str = "0123456789abcdef";
	tmp[0] = hex_str[c / 16];
	tmp[1] = hex_str[c % 16];
	write(1, tmp, 2);
}
