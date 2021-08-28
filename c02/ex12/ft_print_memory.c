/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 07:17:01 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/07 15:30:46 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_print_hex(unsigned char hex)
{
	char			hi;
	char			lo;

	hi = hex / 16;
	lo = hex % 16;
	if (hi >= 0 && hi <= 9)
		hi += '0';
	else
		hi += 'a' - 10;
	if (lo >= 0 && lo <= 9)
		lo += '0';
	else
		lo += 'a' - 10;
	write(1, &hi, 1);
	write(1, &lo, 1);
}

static void	ft_print_addr(void *addr, unsigned long offset)
{
	unsigned long	off;

	off = (unsigned long)addr + offset;
	ft_print_hex(off / (16777216 * 4294967296) % 256);
	ft_print_hex(off / (65536 * 4294967296) % 256);
	ft_print_hex(off / (256 * 4294967296) % 256);
	ft_print_hex(off / 4294967296 % 256);
	ft_print_hex(off / 16777216 % 256);
	ft_print_hex(off / 65536 % 256);
	ft_print_hex(off / 256 % 256);
	ft_print_hex(off % 256);
	write(1, ": ", 2);
}

static void	ft_print_hex_display(void *addr, int offset, int line_len)
{
	int				i;
	unsigned char	*addrc;

	addrc = (unsigned char *)(addr + offset);
	i = 0;
	while (i < line_len)
	{
		ft_print_hex((unsigned char)(addrc[i] % 256));
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

static void	ft_print_plaintext(void *addr, int offset, int line_len)
{
	int				i;
	unsigned char	tmp;

	i = 0;
	while (i < line_len)
	{
		tmp = ((unsigned char *)addr)[offset + i];
		if ((tmp >= 0 && tmp <= 31) || tmp >= 127)
			write(1, ".", 1);
		else
			write(1, &tmp, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	offset;
	int				line_len;

	offset = 0;
	if (!addr || size < 1)
		return (addr);
	while (offset < size)
	{
		ft_print_addr(addr, offset);
		line_len = size - offset;
		if (line_len > 16)
			line_len = 16;
		if (line_len < 0)
			line_len = 0;
		ft_print_hex_display(addr, offset, line_len);
		ft_print_plaintext(addr, offset, line_len);
		offset += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
